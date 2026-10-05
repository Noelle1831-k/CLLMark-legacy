def _analyze_sentence_structure(self, sentence):
        '''
        Analyze the structure of a single sentence.
        '''
        words = word_tokenize(sentence)
        tagged = nltk.pos_tag(words)
        return tagged