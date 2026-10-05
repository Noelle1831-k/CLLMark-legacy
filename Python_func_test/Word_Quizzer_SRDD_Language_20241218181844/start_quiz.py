def start_quiz(self):
        quiz = Quiz(self.user.language, self.user.difficulty, self.user.quiz_type)
        while True:
            question = quiz.generate_question()
            print(question)
            user_answer = input('Enter your answer: ')
            correct = quiz.check_answer(user_answer)
            feedback = quiz.get_feedback()
            print(feedback)
            if correct:
                self.user.update_score(1)
            else:
                self.user.update_score(0)
            cont = input('Do you want to continue? (yes/no): ')
            if cont.lower() != 'yes':
                break
        print('Your score history:', self.user.get_score_history())