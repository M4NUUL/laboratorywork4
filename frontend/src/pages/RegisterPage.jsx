import { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { register } from '../api/authApi';

export default function RegisterPage() {
  const navigate = useNavigate();
  const [form, setForm] = useState({ login: '', password: '', repeat: '' });
  const [error, setError] = useState('');
  const [loading, setLoading] = useState(false);
  const submit = async (event) => {
    event.preventDefault();
    if (!/^[a-zA-Z0-9_.-]{3,40}$/.test(form.login) || form.password.length < 8) return setError('Проверьте логин и длину пароля');
    if (form.password !== form.repeat) return setError('Пароли не совпадают');
    try {
      setLoading(true);
      const user = await register(form.login, form.password);
      localStorage.setItem('login', user.login); localStorage.setItem('role', user.role); localStorage.setItem('token', user.token);
      navigate('/');
    } catch (err) { setError(err.response?.data?.error || 'Ошибка регистрации'); }
    finally { setLoading(false); }
  };
  return <section className="page login-page"><div className="page-heading"><p className="eyebrow">Новая учётная запись</p><h1>Регистрация оператора</h1></div><form className="form" onSubmit={submit}><label>Логин<input value={form.login} onChange={(e) => setForm({ ...form, login: e.target.value })} /></label><label>Пароль<input type="password" value={form.password} onChange={(e) => setForm({ ...form, password: e.target.value })} /></label><label>Повторите пароль<input type="password" value={form.repeat} onChange={(e) => setForm({ ...form, repeat: e.target.value })} /></label>{error && <div className="error">{error}</div>}<button className="button-primary" disabled={loading}>{loading ? 'Создание…' : 'Зарегистрироваться'}</button></form></section>;
}
