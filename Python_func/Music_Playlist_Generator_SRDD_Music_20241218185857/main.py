def main():
    user_prefs = UserPreferences()
    user_prefs.load_preferences()
    # Example of updating preferences
    user_prefs.update_preferences({"genre": "rock", "mood": "energetic"})
    analyzer = MusicAnalyzer()
    # Prompt user for music library input
    music_library = []
    print("Enter your music tracks (type 'done' when finished):")
    while True:
        track = input("Track name: ")
        if track.lower() == 'done':
            break
        music_library.append(track)
    if not music_library:
        print("No tracks entered. Exiting...")
        return
    analysis = analyzer.analyze_library(music_library)
    generator = PlaylistGenerator()
    playlist = generator.generate_playlist(user_prefs.preferences, analysis)
    if not playlist:
        print("No tracks matched your preferences. Try updating your preferences.")
        return
    exporter = MusicExporter()
    preferred_player = "Spotify"  # Example player
    exporter.export_to_player(playlist, preferred_player)