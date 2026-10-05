def start_exercises():
    """
    Starts the vocabulary exercises, allowing the user to choose between a multiple-choice quiz or a fill-in-the-blank exercise.
    Provides additional prompts for better user guidance and error handling.
    """
    print("Choose an exercise:")
    print("1. Multiple-choice quiz")
    print("2. Fill in the blank")
    exercise_choice = input("Enter your choice: ").strip()
    if exercise_choice == "1":
        multiple_choice_quiz()
    elif exercise_choice == "2":
        fill_in_the_blank()
    else:
        print("Invalid choice! Returning to main menu.")