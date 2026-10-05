def search_tracks(self, genre):
        return [track for track in self.tracks if track.genre == genre]