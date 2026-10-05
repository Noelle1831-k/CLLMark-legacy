def suggest_improvement(score):
    '''
    Suggests areas for improvement based on the user's score
    '''
    if score >= 90:
        return "Keep practicing and challenge yourself with more advanced material."
    elif score >= 70:
        return "Review grammar rules and work on vocabulary expansion."
    elif score >= 50:
        return "Focus on grammar and sentence structure. Consider additional practice."
    else:
        return "Consider revisiting fundamental concepts, and don't be discouraged!"