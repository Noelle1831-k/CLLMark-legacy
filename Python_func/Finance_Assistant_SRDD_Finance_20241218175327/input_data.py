def input_data(self):
        '''
        Prompts the user to input their income, expenses, and savings goal, 
        and creates a UserProfile object.
        '''
        try:
            income = float(input("Enter your monthly income: "))
            expenses = float(input("Enter your monthly expenses: "))
            savings_goal = float(input("Enter your savings goal: "))
            self.user_profile = UserProfile(income, expenses, savings_goal)
        except ValueError:
            print("Invalid input. Please enter numeric values.")
            self.input_data()