def present_question(question):
    '''
    Presents the current question to the user and gets their input
    '''
    print(question['question'])
    user_input = get_user_input()
    return user_input