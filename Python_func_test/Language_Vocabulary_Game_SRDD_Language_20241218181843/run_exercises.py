def run_exercises(self):
        exercises = [self.vocab_exercise.word_matching, 
                     self.vocab_exercise.picture_labeling, 
                     self.vocab_exercise.word_association]
        for exercise in exercises:
            exercise()
            self.feedback.provide_feedback()
            self.progress.update_progress()