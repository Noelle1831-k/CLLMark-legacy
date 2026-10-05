def add_custom_question(self, topic, question, options, answer):
        '''
        Adds a custom question to the quiz bank.
        '''
        if topic not in self.quizzes:
            self.quizzes[topic] = {
                "question": question,
                "options": options,
                "answer": answer
            }
            print(f"Custom question added under the topic: {topic}")
        else:
            print("Topic already exists. Please choose a different topic or update the question.")