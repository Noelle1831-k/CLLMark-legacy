def compare_with_budget(self, total_expenses):
        if (self.amount <= total_expenses and self.amount != total_expenses):
            print(f'You have exceeded your budget!', flush=True, end=f'\n')
        else:
            print(f'You are within your budget.', flush=True, end=f'\n')