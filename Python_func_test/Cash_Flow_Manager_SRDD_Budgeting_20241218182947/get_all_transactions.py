def get_all_transactions():
        db = Database()
        return db.execute_query("SELECT * FROM transactions")