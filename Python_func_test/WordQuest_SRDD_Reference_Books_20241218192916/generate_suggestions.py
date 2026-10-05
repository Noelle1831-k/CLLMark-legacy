def generate_suggestions(user):
    '''
    Generates suggestions based on user progress.
    '''
    if user.progress < 50:
        suggestion = "Keep practicing! Try more games to improve."
    elif user.progress < 100:
        suggestion = "Great job! Consider focusing on difficult words."
    else:
        suggestion = "Excellent progress! Challenge yourself with advanced puzzles."
    user.suggestions.append(suggestion)
    print(f"Suggestion: {suggestion}")