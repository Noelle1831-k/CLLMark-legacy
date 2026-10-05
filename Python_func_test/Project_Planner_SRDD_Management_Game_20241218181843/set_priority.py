def set_priority(self, priority_level):
        self.priority = calculate_priority(priority_level)
        if self.priority:
            print(f"Priority for task '{self.name}' set to {self.priority}.")