def format_time(time_str):
    return datetime.strptime(time_str, "%H:%M").strftime("%I:%M %p")