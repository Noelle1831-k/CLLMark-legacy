def _extract_tenses(self, pos_tags):
        '''
        Extract the tenses from the parts of speech tags.
        '''
        tenses = []
        for word, tag in pos_tags:
            if tag.startswith('V'):
                tenses.append((word, tag))
        return tenses