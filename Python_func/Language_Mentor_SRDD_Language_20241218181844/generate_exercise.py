def generate_exercise(self):
        '''
        Generates a new exercise.
        '''
        question = random.choice(self.questions)
        return f"{question} - Answer: {'correct' if random.random() > 0.5 else 'incorrect'}"