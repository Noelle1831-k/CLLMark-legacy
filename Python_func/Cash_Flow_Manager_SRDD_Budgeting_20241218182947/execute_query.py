def execute_query(self, query):
        self.cursor.execute(query)
        self.connection.commit()
        return self.cursor.fetchall()