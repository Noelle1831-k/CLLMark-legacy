def project_exists(self, project_name):
        with self.conn:
            cur = self.conn.execute('SELECT 1 FROM projects WHERE name = ?', (project_name,))
            return cur.fetchone() is not None