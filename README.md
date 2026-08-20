# Лабораторная работа №4 — защищённое SPA

Развитие системы учёта инцидентов безопасности в спортивных сооружениях: React SPA, Express REST API, PostgreSQL, JWT, bcrypt, роли `operator`/`admin`, CRUD, пагинация, фильтры и CI.

## Запуск

1. Скопировать `backend/.env.example` в `backend/.env`, задать PostgreSQL и случайный `JWT_SECRET` длиной от 32 байт.
2. `cd backend && npm install && npm run init-db && npm start`.
3. `cd frontend && npm install && npm start`.
4. Проверка API: `cd backend && npm run smoke`.

Регистрация создаёт оператора; назначение администратора доступно только администратору через управление пользователями. Пароли хранятся как bcrypt-хеши, JWT живёт два часа, сервер проверяет роль на каждом защищённом запросе.

Отчёт: [report/report.md](report/report.md).
