def main():
    user = User()
    if user.authenticate():
        account = Account(user)
        if account.connect():
            expenses = account.retrieve_expenses()
            categorized_expenses = [Expense(e).categorize() for e in expenses]
            dashboard = Dashboard(categorized_expenses)
            dashboard.display()
            generate_report(categorized_expenses)