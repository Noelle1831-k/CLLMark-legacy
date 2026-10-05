def transpose_chords(self, interval):
        transposed_sequence = []
        for chord, duration in self.chord_sequence:
            transposed_chord = self._transpose_chord(chord, interval)
            transposed_sequence.append((transposed_chord, duration))
        self.chord_sequence = transposed_sequence
        print(f"Transposed chords by interval: {interval}")