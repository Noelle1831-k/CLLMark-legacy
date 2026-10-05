def display_playlist(playlist):
    print("\nYour personalized playlist:")
    for song in playlist:
        print(f"- {song['title']} by {song['artist']}")