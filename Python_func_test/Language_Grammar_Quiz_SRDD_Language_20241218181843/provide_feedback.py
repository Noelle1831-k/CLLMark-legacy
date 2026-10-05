def provide_feedback(self):
        feedback = Feedback(self.score, len(self.questions))
        print(feedback.generate_feedback())