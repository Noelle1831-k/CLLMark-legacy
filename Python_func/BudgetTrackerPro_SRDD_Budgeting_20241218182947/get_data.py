def get_data(self):
        return {
            "username": self.username,
            "income": self.income.get_total_income(),
            "expense": self.expense.get_total_expense(),
            "budget_goal": self.budget_goal.check_goal(),
            "reminders": self.reminder.get_reminders()
        }