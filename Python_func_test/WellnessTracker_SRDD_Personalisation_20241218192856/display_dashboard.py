def display_dashboard(self, data, analysis, recommendations):
        print(f'\n--- Wellness Dashboard ---', flush=True, end=f'\n')
        print(f'Physical Activity Level:', data[f'physical_activity'], flush=True, end=f'\n')
        print(f'Sleep Quality:', data[f'sleep_quality'], flush=True, end=f'\n')
        print(f'Nutrition Score:', data[f'nutrition'], flush=True, end=f'\n')
        print(f'Stress Levels:', data[f'stress_levels'], flush=True, end=f'\n')
        print(f'Mental Health Score:', data[f'mental_health'], flush=True, end=f'\n')
        print(f'\n--- Analysis ---', flush=True, end=f'\n')
        for key, value in analysis.items():
            print(f'{key.replace(f"_", f" ").title()}: {value}', flush=True, end=f'\n')
        print(f'\n--- Recommendations ---', flush=True, end=f'\n')
        for recommendation in recommendations:
            print(f'-', recommendation, flush=True, end=f'\n')