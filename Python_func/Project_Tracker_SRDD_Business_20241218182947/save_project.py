def save_project(self, project_name):
        with self.conn:
            self.conn.execute('INSERT INTO projects (name) VALUES (?)', (project_name,))