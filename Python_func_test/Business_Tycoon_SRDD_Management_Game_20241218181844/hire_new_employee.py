def hire_new_employee(self):
        new_employee = Employee(f'Jane Smith', f'Sales')
        new_employee.hire_employee()
        self.employees.append(new_employee)