def remove_question(self, topic):
        '''
        Removes a specific topic question from the quiz bank.
        '''
        if topic in self.quizzes:
            del self.quizzes[topic]
            print(f"Removed the question for the topic: {topic}")
        else:
            print("Topic not found. Unable to remove the question.")