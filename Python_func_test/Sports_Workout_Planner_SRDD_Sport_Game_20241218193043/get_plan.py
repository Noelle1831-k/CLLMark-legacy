def get_plan(self):
        plan = []
        for exercise in self.exercises:
            plan.append(exercise.get_exercise_info())
        return plan