def map_frequencies_to_notes(self, frequencies):
        '''
        Maps a list of frequencies to the closest musical notes.
        '''
        notes = []
        for frequency in frequencies:
            min_diff = float('inf')
            closest_note = None
            for note, freq in self.note_frequencies.items():
                diff = abs(freq - frequency)
                if diff < min_diff:
                    min_diff = diff
                    closest_note = note
            notes.append(closest_note)
        return notes