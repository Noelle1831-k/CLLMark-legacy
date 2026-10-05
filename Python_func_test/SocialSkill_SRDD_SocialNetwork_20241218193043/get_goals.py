def get_goals(self):
        if not self.goals:
            return f'No goals set yet.'
        return f'\n'.join(f'- {goal}' for goal in self.goals)