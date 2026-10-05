def save_employee_data():
    with open(EMPLOYEES_DB, "w") as file:
        json.dump(employees, file)