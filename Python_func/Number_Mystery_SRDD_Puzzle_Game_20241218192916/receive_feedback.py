def receive_feedback(self, is_correct):
        if is_correct:
            print("Correct! Moving to the next level.")
        else:
            print("Incorrect solution. Try again!")