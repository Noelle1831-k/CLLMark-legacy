def add_employee():
    emp_id = input("Enter Employee ID: ")
    name = input("Enter Employee Name: ")
    department = input("Enter Department: ")
    new_employee = Employee(emp_id, name, department)
    employees.append(new_employee.to_dict())
    save_employee_data()
    print(f"Employee {name} added successfully!")