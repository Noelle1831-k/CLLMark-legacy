def __init__(self, description):
        '''
        Initialize a task with a description.
        '''
        self.description = description
        self.status = "Pending"
        self.assigned_employee = None