def add_task(self, description, priority, start_time, end_time):
        task = Task(description, priority, start_time, end_time)
        self.tasks.append(task)