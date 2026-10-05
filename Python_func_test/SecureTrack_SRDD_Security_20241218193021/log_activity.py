def log_activity(activity):
    try:
        with open("activity_log.txt", "a") as log_file:
            log_file.write(f"{activity}\n")
    except IOError as e:
        print(f"Error logging activity: {e}")