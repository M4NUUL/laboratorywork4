const db = require('./db');

async function migrate() {
  await db.query('CREATE INDEX IF NOT EXISTS incidents_created_at_idx ON incidents (created_at DESC)');
  await db.query('CREATE INDEX IF NOT EXISTS incidents_status_idx ON incidents (status)');
  console.log('Migrations applied');
}

migrate().then(() => process.exit(0)).catch((error) => { console.error(error); process.exit(1); });
