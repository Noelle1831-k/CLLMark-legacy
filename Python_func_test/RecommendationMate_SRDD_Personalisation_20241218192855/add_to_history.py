def add_to_history(self, movie_id):
        if movie_id not in self.history:
            self.history.append(movie_id)