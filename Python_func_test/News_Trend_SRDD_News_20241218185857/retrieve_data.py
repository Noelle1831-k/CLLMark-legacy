def retrieve_data(self, table_name):
        '''
        Retrieve data from the database.
        '''
        print(f"Retrieving data from table '{table_name}'...", flush=True)
        self.cursor.execute(f"SELECT * FROM {table_name}")
        return self.cursor.fetchall()