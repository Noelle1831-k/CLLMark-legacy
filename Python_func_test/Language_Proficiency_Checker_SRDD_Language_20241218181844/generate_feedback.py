def generate_feedback(correct_answers, total_questions):
    '''
    Generates feedback based on the number of correct answers
    '''
    score_percentage = (correct_answers / total_questions) * 100
    if score_percentage >= 90:
        return "Excellent job! You have a strong grasp of the language."
    elif score_percentage >= 70:
        return "Good job! You have a solid understanding, but there is room for improvement."
    elif score_percentage >= 50:
        return "You're doing okay, but some areas need work."
    else:
        return "You might want to review the basics more thoroughly."