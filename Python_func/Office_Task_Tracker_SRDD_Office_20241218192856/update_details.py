def update_details(self, title=None, description=None, deadline=None, priority=None):
        '''
        Updates the task details.
        '''
        if title:
            self.title = title
        if description:
            self.description = description
        if deadline:
            self.deadline = deadline
        if priority:
            self.priority = priority