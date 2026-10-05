def main():
    expense_manager = ExpenseManager()
    user_interface = UserInterface(expense_manager)
    user_interface.display_menu()