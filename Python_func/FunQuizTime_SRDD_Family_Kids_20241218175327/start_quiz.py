def start_quiz(self, visuals):
        '''
        Starts the quiz, displays questions, and provides feedback.
        '''
        score = 0
        for question in self.questions:
            visuals.display_question(question)
            user_answer = input("Your answer: ")
            if question.check_answer(user_answer):
                score += 1
            feedback = question.provide_feedback(user_answer)
            visuals.animate_feedback(feedback)
        print(f"Your score: {score}/{len(self.questions)}")