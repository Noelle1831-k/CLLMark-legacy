def filter_songs(song_list, mood_criteria):
    filtered_songs = []
    for song in song_list:
        if song['tempo'] == mood_criteria['tempo'] and song['genre'] == mood_criteria['genre']:
            filtered_songs.append(song)
    return filtered_songs