def determine_feedback(self, accuracy):
        '''
        Determines the feedback message based on the overall accuracy score.
        Arguments:
        accuracy -- The overall accuracy score of the user's pronunciation.
        Returns:
        A feedback message string.
        '''
        print(f"Determining feedback for accuracy: {accuracy:.2f}")
        if accuracy >= self.accuracy_threshold:
            return self.feedback_messages["excellent"]
        elif accuracy >= 0.6:
            return self.feedback_messages["good"]
        elif accuracy >= 0.4:
            return self.feedback_messages["average"]
        else:
            return self.feedback_messages["poor"]