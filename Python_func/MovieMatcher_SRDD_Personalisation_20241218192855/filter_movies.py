def filter_movies(self, preferences):
        filtered = []
        for movie in self.movies:
            if (any(normalize_text(genre) in normalize_text(movie['genres']) for genre in preferences['genres']) or
                any(normalize_text(actor) in normalize_text(movie['actors']) for actor in preferences['actors']) or
                any(normalize_text(director) in normalize_text(movie['directors']) for director in preferences['directors']) or
                any(normalize_text(keyword) in normalize_text(movie['plot']) for keyword in preferences['keywords'])):
                filtered.append(movie)
        return filtered