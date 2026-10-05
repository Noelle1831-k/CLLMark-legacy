def identify_parts_of_speech(self):
        '''
        Identifies parts of speech for each word in the sentence.
        Returns a dictionary mapping words to their parts of speech.
        '''
        pos_mapping = {}
        for word, pos in self.pos_tags:
            pos_mapping[word] = pos
        return pos_mapping