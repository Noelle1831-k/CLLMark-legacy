def create_tables(self):
        '''
        Create the necessary tables for storing budget data.
        '''
        with self.conn:
            self.conn.execute('''
                CREATE TABLE IF NOT EXISTS incomes (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    source TEXT,
                    amount REAL
                )
            ''')
            self.conn.execute('''
                CREATE TABLE IF NOT EXISTS expenses (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    category TEXT,
                    amount REAL
                )
            ''')
            self.conn.execute('''
                CREATE TABLE IF NOT EXISTS goals (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    description TEXT,
                    target_amount REAL
                )
            ''')