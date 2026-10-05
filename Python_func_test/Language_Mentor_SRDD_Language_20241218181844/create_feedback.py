def create_feedback(self, user):
        '''
        Creates feedback for a user.
        '''
        feedback = Feedback(user)
        self.feedbacks.append(feedback)
        return feedback