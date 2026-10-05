def generate_exercises():
    '''
    Provides pronunciation exercises to the user.
    This function generates a set of random pronunciation exercises and asks the user to practice.
    '''
    print("Generating pronunciation exercises...")
    exercises = [
        "Exercise 1: Pronounce 'Bonjour' (French)",
        "Exercise 2: Pronounce 'Hola' (Spanish)",
        "Exercise 3: Pronounce 'Hello' (English)",
        "Exercise 4: Pronounce 'Guten Morgen' (German)",
        "Exercise 5: Pronounce 'Konnichiwa' (Japanese)"
    ]
    # Randomly shuffle exercises
    random.shuffle(exercises)
    for exercise_item in exercises:
        print(exercise_item)
        user_input = input("Press Enter after completing the exercise...")
        evaluate_performance(exercise_item)