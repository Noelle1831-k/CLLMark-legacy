def save_data(self, table_name, trends):
        '''
        Save trend data into the database.
        '''
        print(f"Saving data into table '{table_name}'...")
        self.cursor.execute(f"DELETE FROM {table_name}")  # Clean old data
        for trend, count in trends:
            self.cursor.execute(f"INSERT INTO {table_name} (trend, count) VALUES (?, ?)", (trend, count))
        self.conn.commit()