def generate_feedback(self, result):
        if result > 80:
            return "Excellent performance! Keep up the great work!"
        elif result > 50:
            return "Good job! You're making progress."
        else:
            return "Keep practicing! You'll improve with time."