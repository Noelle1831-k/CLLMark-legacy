def provide_feedback(self, feedback):
        '''
        Provide feedback for the hotel service.
        '''
        self.feedback = feedback
        print(f"{self.name} provided feedback: {self.feedback}")