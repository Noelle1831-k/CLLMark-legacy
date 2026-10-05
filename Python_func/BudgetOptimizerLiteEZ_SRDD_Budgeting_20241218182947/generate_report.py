def generate_report(self):
        '''
        Generates and prints a detailed budget report.
        Includes total income, total expenses, balance, and goal status.
        '''
        balance = self.calculate_balance()
        income_total = sum(income.amount for income in self.incomes)
        expense_total = sum(expense.amount for expense in self.expenses)
        print(f"Total Income: ${income_total}")
        print(f"Total Expenses: ${expense_total}")
        print(f"Balance: ${balance}")
        if self.goal:
            goal_status = self.goal.check_goal_status(balance)
            print(f"Goal Status: {goal_status}")
        self.visualizer.create_pie_chart(self.incomes, self.expenses)
        self.visualizer.create_bar_chart(self.incomes, self.expenses)