def load_exercise_library():
    '''
    Load the exercise library from a JSON file.
    '''
    with open('exercises.json', 'r') as file:
        data = json.load(file)
    return [Exercise(**exercise) for exercise in data]