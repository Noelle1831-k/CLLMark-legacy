def generate_summary(self, expenses):
        print("Summary Report:")
        total_expense = sum(expense.amount for expense in expenses)
        print(f"Total Expenses: ${total_expense:.2f}")
        category_totals = {}
        for expense in expenses:
            if expense.category in category_totals:
                category_totals[expense.category] += expense.amount
            else:
                category_totals[expense.category] = expense.amount
        for category, total in category_totals.items():
            print(f"Category: {category}, Total: ${total:.2f}")