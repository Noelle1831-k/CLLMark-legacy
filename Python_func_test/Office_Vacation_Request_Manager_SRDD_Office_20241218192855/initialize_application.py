def initialize_application():
    print("Welcome to the Employee Vacation Management System!")
    employee.load_employee_data()
    vacation.load_vacation_data()
    print("System Initialized Successfully.\n")