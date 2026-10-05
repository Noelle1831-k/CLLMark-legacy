def give_feedback(score):
    '''
    Provides feedback based on the user's performance score.
    This function gives tailored feedback based on the user's score to encourage improvement.
    '''
    if score >= 8:
        print("Great job! Your pronunciation is excellent!")
    elif score >= 5:
        print("Good effort! You're making progress, keep practicing!")
    else:
        print("Needs improvement. Try focusing on the correct pronunciation of each syllable.")