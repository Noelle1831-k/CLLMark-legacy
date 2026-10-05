def initialize_tables(self):
        """
        Creates necessary tables for the application.
        """
        self.cursor.execute("""
            CREATE TABLE IF NOT EXISTS income (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                amount REAL,
                source TEXT
            )
        """)
        self.cursor.execute("""
            CREATE TABLE IF NOT EXISTS expenses (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                amount REAL,
                category TEXT
            )
        """)
        self.cursor.execute("""
            CREATE TABLE IF NOT EXISTS savings_target (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                target REAL
            )
        """)
        self.conn.commit()