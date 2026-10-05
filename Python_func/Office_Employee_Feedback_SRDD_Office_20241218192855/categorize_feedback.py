def categorize_feedback(self, feedbacks):
        categorized = {'Positive': [], 'Negative': [], 'Neutral': []}
        for feedback in feedbacks:
            if "good" in feedback.lower():
                categorized['Positive'].append(feedback)
            elif "bad" in feedback.lower():
                categorized['Negative'].append(feedback)
            else:
                categorized['Neutral'].append(feedback)
        return categorized