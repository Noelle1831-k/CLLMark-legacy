def get_track(self, title):
        for track in self.tracks:
            if track.title == title:
                return track
        return None