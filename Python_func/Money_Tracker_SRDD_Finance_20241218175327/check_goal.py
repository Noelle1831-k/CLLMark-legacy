def check_goal(self, category, current_amount):
        if category in self.goals:
            return current_amount <= self.goals[category]
        return False