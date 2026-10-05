def analyze_feedback(self, feedbacks):
        analysis = {'Positive': 0, 'Negative': 0, 'Neutral': 0}
        for feedback in feedbacks:
            if "good" in feedback.lower():
                analysis['Positive'] += 1
            elif "bad" in feedback.lower():
                analysis['Negative'] += 1
            else:
                analysis['Neutral'] += 1
        return analysis