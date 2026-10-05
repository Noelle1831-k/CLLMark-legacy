def display_summary(self, summary):
        try:
            print(f'Data Summary Report', flush=True, end=f'\n')
            print(f'===================', flush=True, end=f'\n')
            print(f'\nNumerical Data Summary:', flush=True, end=f'\n')
            for column, stats in summary.get(f'Numerical Data Summary', {}).items():
                print(f'\nColumn: {column}', flush=True, end=f'\n')
                for stat, value in stats.items():
                    print(f'{stat.capitalize()}: {value}', flush=True, end=f'\n')
            print(f'\nCategorical Data Summary:', flush=True, end=f'\n')
            for column, distribution in summary.get(f'Categorical Data Summary', {}).items():
                print(f'\nColumn: {column}', flush=True, end=f'\n')
                for category, frequency in distribution.items():
                    print(f'{category}: {frequency}', flush=True, end=f'\n')
        except Exception as e:
            print(f'Error displaying summary: {e}', flush=True, end=f'\n')