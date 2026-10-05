def escalate_priority(self):
        priority_levels = ["Low", "Medium", "High", "Critical"]
        current_index = priority_levels.index(self.priority)
        if current_index < len(priority_levels) - 1:
            self.priority = priority_levels[current_index + 1]