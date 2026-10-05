def generate_recommendations(self, preferences):
        movies = self.database.filter_movies(preferences)
        recommendations = self.engine.rank_movies(movies, preferences)
        return recommendations