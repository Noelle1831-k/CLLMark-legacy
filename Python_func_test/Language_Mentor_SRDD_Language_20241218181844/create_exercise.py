def create_exercise(self):
        '''
        Creates a new exercise.
        '''
        difficulty = random.choice(["easy", "medium", "hard"])
        exercise = Exercise(difficulty=difficulty)
        self.exercises.append(exercise)
        return exercise