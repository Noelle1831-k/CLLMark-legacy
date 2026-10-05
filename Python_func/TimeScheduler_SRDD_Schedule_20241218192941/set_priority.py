def set_priority(self, task_name, priority):
        self.priorities[task_name] = priority
        print(f"Priority for '{task_name}' set to {priority}.")