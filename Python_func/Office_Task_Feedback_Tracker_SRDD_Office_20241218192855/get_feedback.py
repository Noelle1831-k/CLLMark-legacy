def get_feedback(self, feedback_id):
        for feedback in self.feedback_list:
            if feedback.feedback_id == feedback_id:
                return feedback
        return None