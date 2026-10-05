def add_track(self, title, artist, genre, rating=0):
        track = MusicTrack(title, artist, genre, rating)
        self.tracks.append(track)