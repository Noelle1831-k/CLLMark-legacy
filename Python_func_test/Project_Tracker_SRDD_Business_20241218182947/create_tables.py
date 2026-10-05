def create_tables(self):
        with self.conn:
            self.conn.execute('''
                CREATE TABLE IF NOT EXISTS projects (
                    id INTEGER PRIMARY KEY,
                    name TEXT UNIQUE NOT NULL
                )
            ''')
            self.conn.execute('''
                CREATE TABLE IF NOT EXISTS tasks (
                    id INTEGER PRIMARY KEY,
                    project_id INTEGER,
                    title TEXT,
                    assignee TEXT,
                    deadline TEXT,
                    status TEXT,
                    FOREIGN KEY (project_id) REFERENCES projects (id)
                )
            ''')