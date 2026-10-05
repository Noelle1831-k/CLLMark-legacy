def generate_evaluation(self, similarity):
        if 0.9 < similarity:
            return "Excellent"
        elif 0.75 < similarity:
            return "Good"
        elif 0.5 < similarity:
            return "Fair"
        else:
            return "Poor"