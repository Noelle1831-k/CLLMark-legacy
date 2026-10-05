def rank_movies(self, movies, preferences):
        scored_movies = [(movie, self.calculate_similarity(movie, preferences)) for movie in movies]
        scored_movies.sort(key=lambda x: x[1], reverse=True)
        return [movie[0]['title'] for movie in scored_movies]