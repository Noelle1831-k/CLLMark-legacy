def get_priority(self, task_name):
        return self.priorities.get(task_name, "No priority set")