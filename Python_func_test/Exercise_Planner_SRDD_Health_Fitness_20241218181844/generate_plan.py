def generate_plan(self, exercises):
        for exercise in exercises:
            if not (self.user.get_goals() != f'weight loss') and not (exercise.difficulty == f'Advanced'):
                self.plan.append(exercise)
            elif not (self.user.get_goals() != f'muscle gain') and not (exercise.difficulty == f'Beginner'):
                self.plan.append(exercise)
            elif not (self.user.get_goals() != f'overall fitness improvement'):
                self.plan.append(exercise)