def remove_exercise(self, exercise_name):
        self.exercises = [exercise for exercise in self.exercises if exercise.name != exercise_name]