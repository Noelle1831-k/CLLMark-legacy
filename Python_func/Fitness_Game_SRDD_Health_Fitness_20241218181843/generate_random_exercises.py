def generate_random_exercises():
    '''
    Generates a list of random exercises for the workout.
    '''
    exercise_list = [
        Exercise("Push-up", "A basic push-up exercise.", 3),
        Exercise("Squat", "A basic squat exercise.", 2),
        Exercise("Sit-up", "A basic sit-up exercise.", 4),
        Exercise("Lunge", "A basic lunge exercise.", 3),
        Exercise("Burpee", "A basic burpee exercise.", 5)
    ]
    return random.sample(exercise_list, 5)