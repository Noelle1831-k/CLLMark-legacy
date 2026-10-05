def provide_feedback(self, user_input, recording):
        evaluation = self.current_challenge.evaluate_pronunciation(user_input, recording)
        feedback_instance = feedback.Feedback(evaluation)
        feedback_instance.generate_feedback()