def calculate_days_until_deadline(deadline):
    '''
    Calculate the number of days until the deadline.
    '''
    today = datetime.today()
    deadline_date = datetime.strptime(deadline, '%Y-%m-%d')
    delta = deadline_date - today
    return delta.days