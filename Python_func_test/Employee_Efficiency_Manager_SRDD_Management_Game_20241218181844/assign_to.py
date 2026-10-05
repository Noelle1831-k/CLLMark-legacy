def assign_to(self, employee):
        '''
        Assign the task to an employee.
        '''
        self.assigned_employee = employee
        employee.add_task(self)