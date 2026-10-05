def load_vacation_data():
    try:
        with open(VACATION_DB, "r") as file:
            global vacation_requests
            vacation_requests = json.load(file)
    except FileNotFoundError:
        vacation_requests = []