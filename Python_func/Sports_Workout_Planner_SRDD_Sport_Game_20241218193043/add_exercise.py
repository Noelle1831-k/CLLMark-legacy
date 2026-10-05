def add_exercise(self, name, sets, reps):
        exercise = Exercise(name, sets, reps)
        self.exercises.append(exercise)