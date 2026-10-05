def review_feedback(self, manager_id):
        all_feedback = self.database.get_all_feedback()
        for feedback in all_feedback:
            print(f"Feedback ID: {feedback.feedback_id}, Employee ID: {feedback.employee_id}, Task ID: {feedback.task_id}, Text: {feedback.feedback_text}, Category: {feedback.category}, Status: {feedback.status}")