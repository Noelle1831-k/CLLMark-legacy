def create_exercise(difficulty):
        '''
        Creates an exercise instance based on the given difficulty level.
        '''
        if difficulty == 1:
            return NoteIdentificationExercise(difficulty)
        elif difficulty == 2:
            return IntervalIdentificationExercise(difficulty)
        elif difficulty == 3:
            return CombinedExercise(difficulty)