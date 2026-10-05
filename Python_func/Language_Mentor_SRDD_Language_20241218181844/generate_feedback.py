def generate_feedback(self):
        '''
        Generates feedback based on user performance.
        '''
        if self.user.level > 5:
            return f"Feedback for {self.user.name}: Excellent progress! Keep up the great work!"
        elif self.user.level > 2:
            return f"Feedback for {self.user.name}: Good job! You're improving steadily."
        else:
            return f"Feedback for {self.user.name}: Keep practicing! You'll get better with time."