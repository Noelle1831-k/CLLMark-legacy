def run(self, user):
        print("Running Combined Exercise")
        # Run a note identification exercise
        NoteIdentificationExercise(self.difficulty).run(user)
        # Run an interval identification exercise
        IntervalIdentificationExercise(self.difficulty).run(user)