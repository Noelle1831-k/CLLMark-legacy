def save_vacation_data():
    with open(VACATION_DB, "w") as file:
        json.dump(vacation_requests, file)