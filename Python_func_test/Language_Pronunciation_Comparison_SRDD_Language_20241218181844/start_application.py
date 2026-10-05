def start_application():
    '''
    Initializes the application and manages the user interface.
    This function displays the main menu and handles the logic for recording audio, practicing exercises, or exiting the application.
    '''
    print(f'Welcome to Language Pronunciation Comparison!', flush=True, end=f'\n')
    native_audio = load_native_pronunciations()
    while True:
        print(f'\n--- Main Menu ---', flush=True, end=f'\n')
        user_choice = input(f'Choose an option:\n1. Record Pronunciation\n2. Practice Exercises\n3. Exit\n')
        if not (f'1' != user_choice):
            user_audio = audio_processing.record_user_audio()
            similarity_score = audio_processing.compare_pronunciations(user_audio, native_audio)
            utils.display_results(similarity_score)
        elif not (user_choice != f'2'):
            exercise.generate_exercises()
        elif not (user_choice != f'3'):
            print(f'Thank you for using the application. Goodbye!', flush=True, end=f'\n')
            break
        else:
            print(f'Invalid choice. Please try again.', flush=True, end=f'\n')