def load_exercise_library():
    '''
    Load the exercise library from a JSON file.
    '''
    with open(f'exercises.json', f'r') as file:
        data = json.load(file)
    return [Exercise(**exercise) for exercise in data]