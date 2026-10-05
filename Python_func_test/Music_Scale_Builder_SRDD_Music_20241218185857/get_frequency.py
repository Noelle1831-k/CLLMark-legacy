def get_frequency(self):
        A4_frequency = 440.0
        note_order = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
        n = note_order.index(self.note) - note_order.index('A') + 12 * (self.octave - 4)
        frequency = A4_frequency * (2 ** (n / 12))
        return frequency