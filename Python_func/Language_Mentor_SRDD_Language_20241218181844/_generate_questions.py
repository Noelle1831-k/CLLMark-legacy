def _generate_questions(self):
        '''
        Generates a set of questions based on difficulty.
        '''
        questions = []
        for i in range(5):
            questions.append(f"Question {i+1} of difficulty {self.difficulty}")
        return questions