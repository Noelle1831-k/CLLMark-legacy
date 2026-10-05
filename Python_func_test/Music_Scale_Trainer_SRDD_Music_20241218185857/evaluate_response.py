def evaluate_response(self, exercise, response):
        correct_notes = exercise.get_notes()
        response = response.strip().upper()
        if response == correct_notes:
            return self.feedback_provider.provide_feedback(True)
        else:
            return self.feedback_provider.provide_feedback(False)