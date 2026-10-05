def generate_quiz(self, topics=None):
        '''
        This method generates a customized quiz based on selected topics.
        If no topics are provided, a random set of topics will be included.
        '''
        if not topics:
            topics = list(self.quizzes.keys())
        selected_quiz = {}
        for topic in topics:
            if topic in self.quizzes:
                selected_quiz[topic] = self.quizzes[topic]
        return selected_quiz