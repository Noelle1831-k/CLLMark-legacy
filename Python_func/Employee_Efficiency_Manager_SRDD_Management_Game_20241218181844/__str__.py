def __str__(self):
        '''
        String representation of the task.
        '''
        return f"Task: {self.description}, Status: {self.status}, Assigned to: {self.assigned_employee.name if self.assigned_employee else 'None'}"