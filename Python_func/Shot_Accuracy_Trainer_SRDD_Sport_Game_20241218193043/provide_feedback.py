def provide_feedback(self):
        accuracy = self.calculate_accuracy()
        if self.result == "hit":
            return f"Good shot! Accuracy: {accuracy}%"
        else:
            return f"Missed shot. Accuracy: {accuracy}%"