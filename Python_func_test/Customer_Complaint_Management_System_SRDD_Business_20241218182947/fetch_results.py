def fetch_results(self, query):
        cursor = self.connection.cursor()
        cursor.execute(query)
        return cursor.fetchall()