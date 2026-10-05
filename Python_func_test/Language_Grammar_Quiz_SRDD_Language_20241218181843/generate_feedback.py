def generate_feedback(self):
        percentage = (self.score / self.total_questions) * 100
        if percentage >= 80:
            return "Excellent! You have a strong grasp of the material."
        elif percentage >= 50:
            return "Good job! You have a decent understanding."
        else:
            return "Keep practicing! You'll get better with time."