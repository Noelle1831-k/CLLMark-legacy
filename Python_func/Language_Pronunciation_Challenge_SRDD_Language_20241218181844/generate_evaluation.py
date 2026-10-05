def generate_evaluation(self, similarity):
        if similarity > 0.9:
            return "Excellent"
        elif similarity > 0.75:
            return "Good"
        elif similarity > 0.5:
            return "Fair"
        else:
            return "Poor"