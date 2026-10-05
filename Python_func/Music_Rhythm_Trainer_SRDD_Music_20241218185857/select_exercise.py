def select_exercise(self, exercise_name):
        if exercise_name in self.exercises:
            print(f"Selected exercise: {exercise_name}")
        else:
            print("Invalid exercise selected. Defaulting to 'Clap'.")
            exercise_name = "Clap"
        return exercise_name