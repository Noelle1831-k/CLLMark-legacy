def update_feedback_status(self, feedback_id, new_status):
        feedback = self.database.get_feedback(feedback_id)
        if feedback:
            feedback.update_status(new_status)