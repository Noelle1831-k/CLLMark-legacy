def generate_question(self):
        '''
        Generate a social studies question.
        '''
        questions = [
            ("Who was the first President of the United States?", "George Washington"),
            ("What year did the American Civil War end?", "1865"),
            ("What is the capital of France?", "Paris")
        ]
        question, answer = random.choice(questions)
        return question, answer