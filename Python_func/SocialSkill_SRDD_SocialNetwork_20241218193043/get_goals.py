def get_goals(self):
        if not self.goals:
            return "No goals set yet."
        return "\n".join(f"- {goal}" for goal in self.goals)