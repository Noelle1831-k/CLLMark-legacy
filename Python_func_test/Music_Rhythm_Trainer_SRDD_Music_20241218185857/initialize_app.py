def initialize_app():
    print("Initializing Music Rhythm Trainer...")
    metronome_instance = metronome.Metronome()
    rhythm_patterns_instance = rhythm_patterns.RhythmPattern()
    exercise_instance = exercise.Exercise()
    user_progress_instance = user_progress.UserProgress()
    metronome_instance.start()
    rhythm_patterns_instance.load_patterns()
    while True:
        print("\nAvailable Exercises:")
        exercise_instance.display_exercises()
        selected_exercise = input("Select an exercise by name: ")
        exercise_instance.select_exercise(selected_exercise)
        difficulty = input("Select difficulty level (easy/medium/hard): ")
        exercise_instance.set_difficulty(difficulty)
        performance = exercise_instance.evaluate_performance()
        user_progress_instance.update_progress(performance)
        user_progress_instance.get_feedback()
        cont = input("Do you want to try another exercise? (yes/no): ")
        if cont.lower() != 'yes':
            break
    metronome_instance.stop()