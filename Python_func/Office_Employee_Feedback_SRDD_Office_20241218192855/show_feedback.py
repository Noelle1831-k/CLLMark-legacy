def show_feedback(self, feedback):
        print("Feedback Details:")
        for category, feedbacks in feedback.items():
            print(f"{category}:")
            for fb in feedbacks:
                print(f" - {fb}")