def get_tasks(self, project_name):
        with self.conn:
            cur = self.conn.execute('SELECT id FROM projects WHERE name = ?', (project_name,))
            project_id = cur.fetchone()[0]
            cur = self.conn.execute('SELECT title, assignee, deadline, status FROM tasks WHERE project_id = ?', (project_id,))
            tasks = []
            for row in cur.fetchall():
                task = Task(row[0], row[1], row[2])
                task.update_status(row[3])
                tasks.append(task)
            return tasks