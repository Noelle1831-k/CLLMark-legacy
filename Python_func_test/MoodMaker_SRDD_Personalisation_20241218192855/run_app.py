def run_app():
    user_mood = get_user_mood()
    mood_criteria = analyze_mood(user_mood)
    playlist = generate_playlist(mood_criteria)
    display_playlist(playlist)
    save_playlist(playlist)
    share_playlist(playlist)