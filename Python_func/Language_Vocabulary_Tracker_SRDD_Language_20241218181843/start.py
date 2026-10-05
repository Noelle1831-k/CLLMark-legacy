def start(self):
        '''
        Start the quiz by shuffling the questions and prompting the user for answers.
        '''
        random.shuffle(self.questions)
        answers = []
        for word, definition in self.questions:
            print(f"What is the definition of '{word}'?")
            answer = input("Your answer: ")
            answers.append((word, answer))
        self.evaluate(answers)