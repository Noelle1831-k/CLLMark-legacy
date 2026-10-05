def display_summary(self, expenses):
        total = sum(exp[f'amount'] for exp in expenses)
        print(f'\nSummary', flush=True, end=f'\n')
        print(f'-' * 20, flush=True, end=f'\n')
        print(f'Total Expenses: {utilities.format_currency(total)}', flush=True, end=f'\n')