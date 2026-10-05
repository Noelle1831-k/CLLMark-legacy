def start_exercise(self):
        self.current_exercise = exercise.ExerciseFactory.create_exercise(self.difficulty.level)
        self.current_exercise.run(self.user)