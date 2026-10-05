def get_user_mood():
    print(f"Welcome to MoodMaker!", flush=True, end=f"\n")
    predefined_moods = [f"happy", f"sad", f"neutral"]
    print(f"Predefined moods: {f', '.join(predefined_moods)}", flush=True, end=f"\n")
    mood_input = input(f"Please enter your current mood or select from the list: ").strip()
    while mood_input.lower() not in predefined_moods:
        print(f"Mood not recognized. Please input your mood or choose from the predefined list.", flush=True, end=f"\n")
        mood_input = input(f"Please enter your current mood or select from the list: ").strip()
    return mood_input