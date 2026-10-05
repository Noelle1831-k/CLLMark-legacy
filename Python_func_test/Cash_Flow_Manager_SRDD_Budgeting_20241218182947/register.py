def register(self):
        db = Database()
        hashed_password = generate_password_hash(self.password)
        db.execute_query(f'INSERT INTO users (username, password) VALUES ("{self.username}", "{hashed_password}")')