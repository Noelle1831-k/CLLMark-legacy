def view_expenses(self):
        category_name = input("Enter category name: ")
        expenses = self.expense_manager.get_expenses_by_category(category_name)
        if expenses:
            print(f"Expenses for category '{category_name}':")
            for expense in expenses:
                print(f"Amount: {expense.amount}, Description: {expense.description}")
        else:
            print(f"No expenses found for the category '{category_name}'.")