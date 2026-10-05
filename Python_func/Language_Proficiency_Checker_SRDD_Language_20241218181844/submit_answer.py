def submit_answer(question, user_answer):
    '''
    Submits the user's answer and checks if it is correct
    '''
    from question_manager import validate_answer
    return validate_answer(question, user_answer)