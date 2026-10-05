def format_time_spent(minutes):
    '''
    Format time spent in hours and minutes.
    '''
    hours = minutes // 60
    mins = minutes % 60
    return f'{hours}h {mins}m'