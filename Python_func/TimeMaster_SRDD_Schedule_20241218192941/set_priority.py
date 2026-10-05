def set_priority(self, task_name, priority):
        '''
        Sets the priority of a task.
        '''
        for task in self.tasks:
            if task["name"] == task_name:
                task["priority"] = priority
                break