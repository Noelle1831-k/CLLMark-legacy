def generate_playlist(mood_criteria):
    song_list = get_song_list()
    filtered_songs = filter_songs(song_list, mood_criteria)
    return filtered_songs