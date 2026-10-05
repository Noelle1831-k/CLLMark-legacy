def analyze_pos(self):
        '''
        Analyze the parts of speech of the text.
        '''
        words = word_tokenize(self.text)
        pos_tags = nltk.pos_tag(words)
        return pos_tags