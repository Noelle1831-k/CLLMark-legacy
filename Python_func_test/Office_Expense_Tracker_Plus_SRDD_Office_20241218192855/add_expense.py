def add_expense(self, amount, category, date, description):
        '''
        Adds a new expense to the tracker.
        Parameters:
        amount (float): The amount of the expense.
        category (str): The category of the expense.
        date (str): The date of the expense.
        description (str): A description of the expense.
        '''
        try:
            parsed_date = parse_date(date)
            expense = Expense(amount, category, parsed_date, description)
            self.expenses.append(expense)
            print(f"Expense added: {expense.to_dict()}")
        except ValueError as e:
            print(f"Error adding expense: {e}")