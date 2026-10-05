def log_activity(activity):
    with open("activity.log", "a") as log_file:
        log_file.write(f"{format_date(datetime.now())}: {activity}\n")