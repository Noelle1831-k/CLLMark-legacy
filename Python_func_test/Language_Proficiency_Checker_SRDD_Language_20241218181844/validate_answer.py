def validate_answer(question, user_answer):
    '''
    Validates the user's answer against the correct answer for a given question
    '''
    return question['answer'].lower() == user_answer.lower()