def save_task(self, project_name, task):
        with self.conn:
            cur = self.conn.execute('SELECT id FROM projects WHERE name = ?', (project_name,))
            project_id = cur.fetchone()[0]
            self.conn.execute('''
                INSERT INTO tasks (project_id, title, assignee, deadline, status)
                VALUES (?, ?, ?, ?, ?)
            ''', (project_id, task.title, task.assignee, task.deadline, task.status))