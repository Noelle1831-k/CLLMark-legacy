def search_movies(self, query):
        return [movie for movie in self.movies if query.lower() in movie['title'].lower()]