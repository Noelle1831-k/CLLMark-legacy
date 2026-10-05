def add_employee(self, name, skills):
        '''
        Adds a new employee with a name and a list of skills.
        '''
        employee = Employee(name, skills)
        self.employees.append(employee)