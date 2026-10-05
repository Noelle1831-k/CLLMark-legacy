def register_user(self, username, password):
        # Register a new user
        self.db.query_db("INSERT INTO users (username, password) VALUES (?, ?)", (username, password))