def get_user_mood():
    print("Welcome to MoodMaker!")
    predefined_moods = ["happy", "sad", "neutral"]
    print(f"Predefined moods: {', '.join(predefined_moods)}")
    mood_input = input("Please enter your current mood or select from the list: ").strip()
    while mood_input.lower() not in predefined_moods:
        print("Mood not recognized. Please input your mood or choose from the predefined list.")
        mood_input = input("Please enter your current mood or select from the list: ").strip()
    return mood_input