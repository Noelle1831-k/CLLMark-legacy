def calculate_workload(self):
        '''
        Calculates and updates the workload for each employee.
        '''
        for employee in self.employees:
            employee.workload = calculate_workload(employee.id)