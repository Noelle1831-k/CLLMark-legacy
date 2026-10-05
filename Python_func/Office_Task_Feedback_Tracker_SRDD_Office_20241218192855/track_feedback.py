def track_feedback(self, feedback_id):
        feedback = self.database.get_feedback(feedback_id)
        if feedback:
            return feedback.status
        return "Feedback not found"