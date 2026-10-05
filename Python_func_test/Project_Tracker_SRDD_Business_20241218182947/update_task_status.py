def update_task_status(self, project_name, task_title, status):
        with self.conn:
            cur = self.conn.execute('SELECT id FROM projects WHERE name = ?', (project_name,))
            project_id = cur.fetchone()[0]
            cur = self.conn.execute('''
                UPDATE tasks
                SET status = ?
                WHERE project_id = ? AND title = ?
            ''', (status, project_id, task_title))
            return cur.rowcount > 0