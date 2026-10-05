def receive_feedback(self, feedback):
        '''
        Receive feedback and update performance and motivation.
        '''
        self.performance += feedback.rating
        self.motivation += feedback.rating // 2