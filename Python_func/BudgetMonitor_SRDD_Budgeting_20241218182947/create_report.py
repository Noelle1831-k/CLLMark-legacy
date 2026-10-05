def create_report(self, user_data):
        print("\n--- Financial Report ---")
        print("Income:")
        for income in user_data['income']:
            print(f"Category: {income['category']}, Amount: {income['amount']}")
        print("\nExpenses:")
        for expense in user_data['expenses']:
            print(f"Category: {expense['category']}, Amount: {expense['amount']}")
        total_income = sum(item['amount'] for item in user_data['income'])
        total_expenses = sum(item['amount'] for item in user_data['expenses'])
        print(f"\nTotal Income: {total_income}")
        print(f"Total Expenses: {total_expenses}")
        print(f"Net Savings: {total_income - total_expenses}")