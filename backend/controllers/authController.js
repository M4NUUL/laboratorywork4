const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const db = require('../db');

const issueToken = (user) => jwt.sign(
  { sub: user.id, login: user.login, role: user.role },
  process.env.JWT_SECRET,
  { expiresIn: '2h', issuer: 'sport-security-api' }
);

const login = async (req, res) => {
  const loginValue = String(req.body.login || '').trim();
  const password = String(req.body.password || '');
  if (!loginValue || !password) return res.status(400).json({ error: 'Введите логин и пароль' });
  try {
    const { rows } = await db.query('SELECT id, login, password_hash, role FROM users WHERE login = $1', [loginValue]);
    if (!rows[0] || !(await bcrypt.compare(password, rows[0].password_hash))) {
      return res.status(401).json({ error: 'Неверные учётные данные' });
    }
    const { password_hash, ...user } = rows[0];
    res.json({ ...user, token: issueToken(user) });
  } catch (error) {
    console.error(error);
    res.status(500).json({ error: 'Ошибка сервера' });
  }
};

const register = async (req, res) => {
  const loginValue = String(req.body.login || '').trim();
  const password = String(req.body.password || '');
  if (!/^[a-zA-Z0-9_.-]{3,40}$/.test(loginValue) || password.length < 8) {
    return res.status(400).json({ error: 'Логин: 3–40 символов; пароль: минимум 8 символов' });
  }
  try {
    const passwordHash = await bcrypt.hash(password, 12);
    const { rows } = await db.query(
      `INSERT INTO users (login, password_hash, role) VALUES ($1, $2, 'operator') RETURNING id, login, role`,
      [loginValue, passwordHash]
    );
    res.status(201).json({ ...rows[0], token: issueToken(rows[0]) });
  } catch (error) {
    if (error.code === '23505') return res.status(409).json({ error: 'Логин уже занят' });
    console.error(error);
    res.status(500).json({ error: 'Ошибка сервера' });
  }
};

module.exports = { login, register };
