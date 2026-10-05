def get_feedback(self):
        feedback = {
            "Excellent": "Outstanding performance! Keep up the great work!",
            "Good": "Good job! You're improving steadily.",
            "Needs Improvement": "Keep practicing! You'll get there with time."
        }
        print(f"Feedback: {feedback[self.progress['session']]}")