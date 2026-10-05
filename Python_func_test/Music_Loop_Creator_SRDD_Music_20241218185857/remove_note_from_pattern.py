def remove_note_from_pattern(self, note):
        '''
        Removes a note from the pattern.
        '''
        self.notes = [n for n in self.notes if not (note == n[0])]