def main():
    try:
        # Load phrases from a data source
        phrases_data = load_phrases('phrases.json')
        # Create a new user with input validation
        username = input("Enter your username: ")
        proficiency_level = input("Enter your proficiency level (beginner/intermediate/advanced): ")
        learning_goals = input("Enter your learning goals separated by commas (e.g., greetings, dining): ").split(',')
        user = User(username=username.strip(), proficiency_level=proficiency_level.strip(), learning_goals=[goal.strip() for goal in learning_goals])
        # Create a phrasebook for the user
        phrasebook = Phrasebook()
        # Add phrases to the phrasebook
        for category, phrases in phrases_data.items():
            phrasebook.add_category(category)
            for phrase_data in phrases:
                phrase = Phrase(text=phrase_data['text'], audio_pronunciation=phrase_data['audio'], examples=phrase_data['examples'])
                phrasebook.add_phrase(category, phrase)
        # Assign the phrasebook to the user
        user.phrasebook = phrasebook
        # Generate a quiz for the user
        quiz = Quiz(user=user)
        quiz.generate_quiz()
        # Generate exercises for the user
        exercise = Exercise(user=user)
        exercise.generate_exercise()
        # Save user progress
        save_progress(user, 'progress.json')
        # Load user progress
        loaded_user = load_progress('progress.json')
        # Print user progress
        print("User Progress:")
        print(loaded_user.get_progress())
    except Exception as e:
        print(f"An error occurred: {e}")