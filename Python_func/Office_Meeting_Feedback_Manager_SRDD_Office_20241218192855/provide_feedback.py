def provide_feedback(self, meeting, comments, rating):
        feedback = Feedback(self.employee_id, comments, rating)
        meeting.add_feedback(feedback)