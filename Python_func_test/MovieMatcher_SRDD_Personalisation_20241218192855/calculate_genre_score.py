def calculate_genre_score(movie_genres, user_genres):
    return sum(1 for genre in user_genres if genre in movie_genres)