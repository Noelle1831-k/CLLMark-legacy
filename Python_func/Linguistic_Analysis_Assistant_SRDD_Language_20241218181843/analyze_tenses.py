def analyze_tenses(self):
        '''
        Analyze the verb tenses of the text.
        '''
        words = word_tokenize(self.text)
        pos_tags = nltk.pos_tag(words)
        tenses = self._extract_tenses(pos_tags)
        return tenses