def set_budget(self):
        category = input(f'Enter budget category: ')
        amount = float(input(f'Enter budget amount: '))
        self.user.budget.set_budget(category, amount)
        print(f'Budget for "{category}" set to {amount}.', flush=True, end=f'\n')