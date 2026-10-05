def view_feedback(self):
        if not self.feedback:
            print("No feedback available.")
        else:
            print("Your feedback:")
            for feedback in self.feedback:
                print(feedback)