def start_application():
    '''
    Initializes the application and manages the user interface.
    This function displays the main menu and handles the logic for recording audio, practicing exercises, or exiting the application.
    '''
    print("Welcome to Language Pronunciation Comparison!")
    native_audio = load_native_pronunciations()
    while True:
        print("\n--- Main Menu ---")
        user_choice = input("Choose an option:\n1. Record Pronunciation\n2. Practice Exercises\n3. Exit\n")
        if user_choice == '1':
            user_audio = audio_processing.record_user_audio()
            similarity_score = audio_processing.compare_pronunciations(user_audio, native_audio)
            utils.display_results(similarity_score)
        elif user_choice == '2':
            exercise.generate_exercises()
        elif user_choice == '3':
            print("Thank you for using the application. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")