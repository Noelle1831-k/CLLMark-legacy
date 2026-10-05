def generate_vacation_trends():
    start_dates = [req[f'start_date'] for req in vacation.vacation_requests]
    trends = Counter(start_dates)
    print(f'\nVacation Trends:', flush=True, end=f'\n')
    for date, count in trends.items():
        print(f'{date}: {count} requests', flush=True, end=f'\n')