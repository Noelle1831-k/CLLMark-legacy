def display_feedback(self):
        '''
        Provide feedback to the user based on their quiz performance.
        '''
        if self.score == len(self.questions):
            print("Excellent! You have mastered all the words!")
        elif self.score > len(self.questions) // 2:
            print("Good job! You are on the right track.")
        else:
            print("Keep practicing! You can improve.")