def create_task(self, name, description, priority):
        '''
        Creates a new task.
        '''
        task = {
            "name": name,
            "description": description,
            "priority": priority,
            "time_slot": None,
            "progress": "Not Started"
        }
        self.tasks.append(task)