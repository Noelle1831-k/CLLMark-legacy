def __init__(self, title, description, deadline, priority):
        '''
        Initializes a new task with the given details.
        '''
        self.title = title
        self.description = description
        self.deadline = deadline
        self.priority = priority
        self.completed = False