def adjust_tempo(self, tracks, factor):
        for track in tracks:
            self._adjust_tempo(track, factor)