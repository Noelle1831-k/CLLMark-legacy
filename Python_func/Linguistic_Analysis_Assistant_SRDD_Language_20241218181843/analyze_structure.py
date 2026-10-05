def analyze_structure(self):
        '''
        Analyze the sentence structure of the text.
        '''
        sentences = sent_tokenize(self.text)
        structure_analysis = []
        for sentence in sentences:
            structure_analysis.append(self._analyze_sentence_structure(sentence))
        return structure_analysis