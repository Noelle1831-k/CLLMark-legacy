def determine_sentence_structure(self):
        '''
        Determines the sentence structure by analyzing the sequence of parts of speech.
        Returns a list of parts of speech.
        '''
        structure = []
        for _, pos in self.pos_tags:
            structure.append(pos)
        return structure