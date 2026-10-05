def status(self):
        '''
        Return a string representation of the employee's current status.
        '''
        return f"{self.name} ({self.role}) - Performance: {self.performance}, Motivation: {self.motivation}"