def generate():
        db = Database()
        transactions = db.execute_query("SELECT * FROM transactions")
        total_income = sum(t['amount'] for t in transactions if t['amount'] > 0)
        total_expense = sum(t['amount'] for t in transactions if t['amount'] < 0)
        return {
            'total_income': total_income,
            'total_expense': total_expense,
            'net_cash_flow': total_income + total_expense
        }