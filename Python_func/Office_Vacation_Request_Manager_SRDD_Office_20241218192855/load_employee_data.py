def load_employee_data():
    try:
        with open(EMPLOYEES_DB, "r") as file:
            global employees
            employees = json.load(file)
    except FileNotFoundError:
        employees = []