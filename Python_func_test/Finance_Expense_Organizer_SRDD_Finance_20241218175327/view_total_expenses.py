def view_total_expenses(self):
        total = self.expense_manager.get_total_expenses()
        print(f'Total Expenses: {total}', flush=True, end='\n')