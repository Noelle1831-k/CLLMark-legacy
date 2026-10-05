def run_quiz(self):
        for question in self.questions:
            print(question.prompt)
            answer = input("Your answer: ")
            if question.check_answer(answer):
                print("Correct!")
                self.score += 1
            else:
                print("Incorrect!")