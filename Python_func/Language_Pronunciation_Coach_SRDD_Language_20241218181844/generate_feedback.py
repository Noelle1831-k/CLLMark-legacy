def generate_feedback(self, comparison_result):
        if comparison_result > 0.8:
            return "Excellent pronunciation!"
        elif comparison_result > 0.5:
            return "Good, but there's room for improvement."
        else:
            return "Needs improvement. Try again."