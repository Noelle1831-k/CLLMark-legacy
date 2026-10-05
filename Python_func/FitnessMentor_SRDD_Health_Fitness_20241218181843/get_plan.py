def get_plan(self):
        return [exercise.get_exercise_info() for exercise in self.exercises]