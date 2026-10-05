def add_task(self, description, deadline, required_skills):
        '''
        Adds a task to the list with a description, deadline, and required skills.
        '''
        task = Task(description, deadline, required_skills)
        self.tasks.append(task)