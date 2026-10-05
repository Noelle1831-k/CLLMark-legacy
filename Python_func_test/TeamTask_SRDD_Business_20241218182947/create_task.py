def create_task(self, task):
        self.tasks.append(task)
        task.assignee.assign_task(task)  # Ensure task is added to the user's task list