def generate_vacation_trends():
    start_dates = [req["start_date"] for req in vacation.vacation_requests]
    trends = Counter(start_dates)
    print("\nVacation Trends:")
    for date, count in trends.items():
        print(f"{date}: {count} requests")