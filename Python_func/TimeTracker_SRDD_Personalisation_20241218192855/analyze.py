def analyze(self, user):
        '''
        Analyze user tasks, including their priorities and overdue status.
        '''
        self.analysis = {"High": 0, "Medium": 0, "Low": 0}
        self.overdue_tasks = []
        self.completion_times = []
        for task in user.get_tasks():
            # Increment task count based on priority
            if task.priority in self.analysis:
                self.analysis[task.priority] += 1
            else:
                self.analysis[task.priority] = 1
            # Check for overdue tasks
            if task.is_due():
                self.overdue_tasks.append(task.name)