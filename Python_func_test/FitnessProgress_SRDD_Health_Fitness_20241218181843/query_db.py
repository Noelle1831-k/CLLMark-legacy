def query_db(self, query, params=()):
        # Execute a query on the database with parameters
        self.cursor.execute(query, params)
        self.conn.commit()
        return self.cursor.fetchall()