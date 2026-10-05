def plot_income_vs_expenses(self):
        '''
        Plots a line chart comparing monthly income and expenses for the user.
        '''
        monthly_income = self._get_monthly_totals(self.user.income)
        monthly_expenses = self._get_monthly_totals(self.user.expenses)
        months = sorted(set(monthly_income.keys()).union(set(monthly_expenses.keys())))
        income_values = [monthly_income.get(month, 0) for month in months]
        expense_values = [monthly_expenses.get(month, 0) for month in months]
        plt.figure(figsize=(12, 6))
        plt.plot(months, income_values, marker='o', label='Income', color='#ff9999')
        plt.plot(months, expense_values, marker='o', label='Expenses', color='#66b3ff')
        plt.xlabel('Month')
        plt.ylabel('Amount')
        plt.title(f"Monthly Income vs Expenses for {self.user.name}")
        plt.legend()
        plt.xticks(rotation=45, ha='right')
        plt.tight_layout()
        plt.show()