def validate_date(date_str):
    try:
        datetime.strptime(date_str, f'%Y-%m-%d')
        return True
    except ValueError:
        return False