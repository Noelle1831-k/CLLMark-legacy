def login_user(self, username, password):
        # Authenticate a user
        result = self.db.query_db("SELECT * FROM users WHERE username=? AND password=?", (username, password))
        return len(result) > 0