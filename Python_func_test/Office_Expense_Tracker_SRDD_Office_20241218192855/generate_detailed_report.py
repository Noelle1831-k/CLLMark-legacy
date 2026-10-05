def generate_detailed_report(self, expenses):
        print("\nDetailed Report:")
        for expense in expenses:
            print(f"Date: {expense.date}, Category: {expense.category}, Amount: ${expense.amount:.2f}, Description: {expense.description}")