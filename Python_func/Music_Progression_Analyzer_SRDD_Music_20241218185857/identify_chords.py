def identify_chords(self, chord_sequence):
        identified_chords = []
        for chord in chord_sequence:
            identified_chords.append(self._identify_single_chord(chord))
        print(f"Identified chords: {identified_chords}")
        return identified_chords