def _shift_pitch(self, track, semitones):
        factor = 2 ** (semitones / 12)
        track['data'] = [x * factor for x in track['data']]