def login(self):
        db = Database()
        result = db.execute_query(f"SELECT password FROM users WHERE username='{self.username}'")
        if result:
            stored_password = result[0][0]
            return check_password_hash(stored_password, self.password)
        return False