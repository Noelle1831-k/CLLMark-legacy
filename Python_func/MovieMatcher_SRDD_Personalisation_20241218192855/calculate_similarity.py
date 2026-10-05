def calculate_similarity(self, movie, preferences):
        genre_score = calculate_genre_score(movie['genres'], preferences['genres'])
        actor_score = sum(1 for actor in preferences['actors'] if actor in movie['actors'])
        director_score = sum(1 for director in preferences['directors'] if director in movie['directors'])
        keyword_score = sum(1 for keyword in preferences['keywords'] if keyword in movie['plot'])
        return genre_score + actor_score + director_score + keyword_score