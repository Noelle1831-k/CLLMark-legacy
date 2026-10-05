def build_tree(self, tagged_sentence):
        '''
        Builds a syntax tree from the tagged sentence.
        '''
        parser = nltk.ChartParser(self.grammar)
        trees = list(parser.parse([word for word, tag in tagged_sentence]))
        return trees[0] if trees else None