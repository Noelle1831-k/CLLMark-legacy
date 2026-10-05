def get_question(idx, questions):
    '''
    Returns a question by index
    '''
    if 0 <= idx < len(questions):
        return questions[idx]
    else:
        raise IndexError("Question index out of range")