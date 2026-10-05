def highlight_keys(self, notes):
        '''
        Highlights the keys corresponding to the scale notes.
        '''
        highlighted_keys = [self.keys[note % 12] for note in notes]
        print("Highlighted Keys: ", highlighted_keys)