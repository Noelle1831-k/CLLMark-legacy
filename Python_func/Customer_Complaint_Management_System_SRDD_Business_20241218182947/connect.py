def connect(self):
        return sqlite3.connect('complaints.db')