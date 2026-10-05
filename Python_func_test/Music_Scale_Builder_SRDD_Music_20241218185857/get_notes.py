def get_notes(self):
        chord_types = {
            'major': [0, 4, 7],
            'minor': [0, 3, 7],
            'diminished': [0, 3, 6],
            'augmented': [0, 4, 8]
        }
        intervals = chord_types.get(self.type, [])
        note_order = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
        root_index = note_order.index(self.root)
        notes = [(note_order[(root_index + interval) % 12]) for interval in intervals]
        return notes