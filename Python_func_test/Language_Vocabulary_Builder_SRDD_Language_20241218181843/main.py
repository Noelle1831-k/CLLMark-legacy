def main():
    username = input("Enter your username: ")
    language = input("Enter the language you want to learn: ")
    user_instance = user.User(username, language)
    vocab_instance = vocabulary.Vocabulary(language)
    progress_tracker_instance = progress_tracker.ProgressTracker(user_instance)
    interactive_learning_instance = interactive_learning.InteractiveLearning(user_instance, vocab_instance)
    while True:
        print("\nMenu:")
        print("1. Add a new word")
        print("2. Take a quiz")
        print("3. View progress")
        print("4. Start interactive learning session")
        print("5. Exit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            word = input("Enter the word: ")
            meaning = input("Enter the meaning: ")
            vocab_instance.add_word(word, meaning)
            user_instance.add_word(word)
        elif choice == 2:
            quiz_instance = quiz.Quiz(user_instance, vocab_instance)
            quiz_instance.generate_question()
        elif choice == 3:
            progress_tracker_instance.get_progress_report()
        elif choice == 4:
            interactive_learning_instance.start_session()
        elif choice == 5:
            break
        else:
            print("Invalid choice. Please try again.")