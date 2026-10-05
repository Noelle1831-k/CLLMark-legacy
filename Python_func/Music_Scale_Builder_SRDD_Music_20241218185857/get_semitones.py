def get_semitones(self):
        note_order = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
        start_index = note_order.index(self.start_note)
        end_index = note_order.index(self.end_note)
        semitones = (end_index - start_index) % 12
        return semitones