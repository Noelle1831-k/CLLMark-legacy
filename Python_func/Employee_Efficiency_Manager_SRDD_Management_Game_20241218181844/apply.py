def apply(self, employees):
        '''
        Apply the strategy to a list of employees.
        '''
        for employee in employees:
            employee.performance += self.effect
            employee.motivation += self.effect // 2