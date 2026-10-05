def save_playlist(playlist):
    try:
        with open('playlist.txt', 'w') as file:
            for song in playlist:
                file.write(f"{song['title']} by {song['artist']}\n")
        print("Playlist saved successfully!")
    except IOError as e:
        print(f"Error saving the playlist: {e}")