def categorize_feedback(self, feedback_id, category):
        feedback = self.database.get_feedback(feedback_id)
        if feedback:
            feedback.category = category