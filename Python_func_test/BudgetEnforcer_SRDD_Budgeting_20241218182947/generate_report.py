def generate_report(self):
        total_expenses = calculate_total_expenses(self.user.expenses)
        remaining_budget = calculate_remaining_budget(self.user.budget, total_expenses)
        # Display detailed financial report
        print(f"Total Expenses: {format_currency(total_expenses)}")
        print(f"Remaining Budget: {format_currency(remaining_budget)}")
        print(self.gamification.get_status())