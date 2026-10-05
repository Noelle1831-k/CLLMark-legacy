def handle_choice(choice, current_user):
    '''
    Handles user menu choices.
    '''
    if choice == '1':
        games.WordMatchingGame().play(current_user)
    elif choice == '2':
        games.PuzzleGame().play(current_user)
    elif choice == '3':
        games.FillInTheBlanksGame().play(current_user)
    elif choice == '4':
        print(f"Your progress: {current_user.progress}", flush=True)
    elif choice == '5':
        suggestions.generate_suggestions(current_user)
    elif choice == '6':
        user.save_user_data(current_user)
        print("Goodbye!", flush=True)
        exit()
    else:
        print("Invalid choice. Please try again.", flush=True)