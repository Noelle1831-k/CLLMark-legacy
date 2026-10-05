def provide_feedback(self, answer, correct_answer):
        '''
        Provides feedback on the user's answer.
        '''
        if answer == correct_answer:
            return "Correct!"
        else:
            return f"Incorrect. The correct answer was {correct_answer}."