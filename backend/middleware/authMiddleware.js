const jwt = require('jsonwebtoken');

const getBearerToken = (req) => {
  const [scheme, token] = (req.headers.authorization || '').split(' ');
  return scheme === 'Bearer' ? token : '';
};

const authenticate = (req, res, next) => {
  const token = getBearerToken(req);
  if (!token) return res.status(401).json({ error: 'Требуется вход в систему' });
  try {
    const payload = jwt.verify(token, process.env.JWT_SECRET, { issuer: 'sport-security-api' });
    req.user = { id: Number(payload.sub), login: payload.login, role: payload.role };
    next();
  } catch {
    res.status(401).json({ error: 'Токен недействителен или просрочен' });
  }
};

const allowRoles = (...roles) => (req, res, next) => authenticate(req, res, () => {
  if (!roles.includes(req.user.role)) return res.status(403).json({ error: 'Недостаточно прав' });
  next();
});

module.exports = { authenticate, adminOnly: allowRoles('admin'), operatorOrAdmin: allowRoles('operator', 'admin') };
