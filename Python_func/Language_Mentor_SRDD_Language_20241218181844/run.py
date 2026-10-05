def run(self):
        '''
        Runs the main application loop.
        '''
        for user in self.users:
            exercise = self.exercise_manager.create_exercise()
            user.update_progress(exercise)
            feedback = self.feedback_manager.create_feedback(user)
            self.feedback_manager.deliver_feedback(user, feedback)