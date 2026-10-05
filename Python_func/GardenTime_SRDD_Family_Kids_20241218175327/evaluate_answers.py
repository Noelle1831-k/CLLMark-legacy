def evaluate_answers(self, answers):
        '''
        This function is designed to evaluate answers given by the user
        and return feedback based on their responses.
        '''
        print("Evaluating your answers...")
        feedback = []
        for topic, answer in answers.items():
            if topic in self.quizzes:
                correct_answer = self.quizzes[topic]["answer"]
                if answer == correct_answer:
                    feedback.append(f"Correct! The answer for '{topic}' is '{answer}'.")
                else:
                    feedback.append(f"Incorrect. The correct answer for '{topic}' is '{correct_answer}'.")
            else:
                feedback.append(f"Invalid topic: {topic}. No such question available.")
        return feedback