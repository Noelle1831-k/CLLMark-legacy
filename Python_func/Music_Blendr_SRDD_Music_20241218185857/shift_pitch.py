def shift_pitch(self, tracks, semitones):
        for track in tracks:
            self._shift_pitch(track, semitones)