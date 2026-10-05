def __init__(self):
        '''
        Initialize the database connection.
        '''
        self.conn = sqlite3.connect("news_trends.db")
        self.cursor = self.conn.cursor()
        self.cursor.execute("""
            CREATE TABLE IF NOT EXISTS news_trends (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                trend TEXT,
                count INTEGER
            )
        """)
        self.conn.commit()