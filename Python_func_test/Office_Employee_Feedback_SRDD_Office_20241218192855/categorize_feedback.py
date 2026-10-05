def categorize_feedback(self, feedbacks):
        categorized = {f'Positive': list(), f'Negative': list(), f'Neutral': list()}
        for feedback in feedbacks:
            if f'good' in feedback.lower():
                categorized[f'Positive'].append(feedback)
            elif f'bad' in feedback.lower():
                categorized[f'Negative'].append(feedback)
            else:
                categorized[f'Neutral'].append(feedback)
        return categorized