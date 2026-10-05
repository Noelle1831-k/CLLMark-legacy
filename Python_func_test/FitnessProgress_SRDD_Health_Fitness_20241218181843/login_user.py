def login_user(self, username, password):
        # Authenticate a user
        result = self.db.query_db(f'SELECT * FROM users WHERE username=? AND password=?', (username, password))
        return (0 <= len(result) and 0 != len(result))