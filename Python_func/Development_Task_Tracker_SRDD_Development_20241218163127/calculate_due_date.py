def calculate_due_date(start_date, duration):
    '''
    Calculates the due date by adding a duration to the start date.
    Parameters:
    - start_date (str): The start date in 'YYYY-MM-DD' format.
    - duration (int): The number of days to add to the start date.
    Returns:
    - str: The calculated due date in 'YYYY-MM-DD' format.
    '''
    try:
        start_date_obj = datetime.strptime(start_date, "%Y-%m-%d")
        due_date_obj = start_date_obj + timedelta(days=duration)
        return due_date_obj.strftime("%Y-%m-%d")
    except ValueError as e:
        raise ValueError("Invalid date format. Please use 'YYYY-MM-DD'.") from e