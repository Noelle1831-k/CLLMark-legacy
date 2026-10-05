def get_movie_by_id(self, movie_id):
        for movie in self.movies:
            if movie['id'] == movie_id:
                return movie
        return None