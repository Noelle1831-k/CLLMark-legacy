def provide_feedback(self, user, feedback):
        self.feedbacks.append({
            "user": user.name,
            "feedback": feedback
        })
        print(f"Feedback for {user.name}: {feedback}")