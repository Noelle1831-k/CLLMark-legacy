def handle_user_choice(choice):
    """
    Handles the user's choice from the menu and invokes the corresponding function. 
    Additional validation has been added to ensure input is valid.
    """
    if choice == "1":
        word = input("Enter a new word: ").strip()
        meaning = input("Enter the meaning: ").strip()
        example = input("Enter an example sentence: ").strip()
        vocabulary.add_word(word, meaning, example)
    elif choice == "2":
        language_exercises.start_exercises()
    elif choice == "3":
        progress_tracker.display_progress()
    elif choice == "4":
        print("Thank you for using Vocabulary Builder. Goodbye!")
        exit(0)
    else:
        print("Invalid choice! Please try again.")