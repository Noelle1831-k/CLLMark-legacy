def add_preference(self, genre):
        if genre not in self.preferences:
            self.preferences.append(genre)