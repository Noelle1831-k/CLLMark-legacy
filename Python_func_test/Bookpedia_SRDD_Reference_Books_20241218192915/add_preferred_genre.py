def add_preferred_genre(self, genre):
        if genre not in self.preferred_genres:
            self.preferred_genres.append(genre)