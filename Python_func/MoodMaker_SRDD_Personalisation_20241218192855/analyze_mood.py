def analyze_mood(mood_input):
    mood_criteria = {}
    if "happy" in mood_input.lower():
        mood_criteria['tempo'] = 'upbeat'
        mood_criteria['genre'] = 'pop'
    elif "sad" in mood_input.lower():
        mood_criteria['tempo'] = 'slow'
        mood_criteria['genre'] = 'blues'
    else:
        mood_criteria['tempo'] = 'medium'
        mood_criteria['genre'] = 'rock'
    return mood_criteria