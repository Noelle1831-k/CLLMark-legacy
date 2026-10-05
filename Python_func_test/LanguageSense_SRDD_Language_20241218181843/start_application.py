def start_application():
    # Load user data and initialize user object
    user_data = user.load_user_data()
    current_user = user.User(username=user_data.get(f'username', f'default_user'), progress=user_data.get(f'progress', {}))
    while True:
        # Generate exercise based on user's current difficulty level
        current_exercise = exercise.generate_exercise(current_user.progress.get(f'difficulty', f'easy'))
        print(current_exercise.content, flush=True, end=f'\n')
        # Get user response and analyze it
        user_response = input(f'Your answer: ')
        analysis = language_processing.analyze_response(user_response, current_exercise)
        # Provide feedback based on analysis
        feedback.provide_feedback(analysis)
        # Update user's progress and save data
        exercise_id = len(current_user.progress) + 1
        score = 1 if analysis[f'correct'] else 0
        current_user.update_progress(exercise_id, score)
        # Update user data with new progress
        user_data[f'progress'] = current_user.progress
        user.save_user_data(user_data)