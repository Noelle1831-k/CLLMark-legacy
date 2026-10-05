def generate_summary(self, budget_tracker):
        total_income = budget_tracker.get_total_income()
        total_expenses = budget_tracker.get_total_expenses()
        balance = budget_tracker.get_balance()
        summary = 'Budget Summary:\n'
        summary += f'Total Income: {format_currency(total_income)}\n'
        summary += f'Total Expenses: {format_currency(total_expenses)}\n'
        summary += f'Balance: {format_currency(balance)}\n'
        return summary