def add(self):
        db = Database()
        db.execute_query(f"INSERT INTO transactions (amount, description) VALUES ('{self.amount}', '{self.description}')")