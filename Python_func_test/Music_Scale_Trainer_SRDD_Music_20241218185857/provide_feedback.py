def provide_feedback(self, is_correct):
        if is_correct:
            return "Correct! Well done."
        else:
            return "Incorrect. Try again."