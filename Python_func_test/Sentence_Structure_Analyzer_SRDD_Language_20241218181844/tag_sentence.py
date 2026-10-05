def tag_sentence(self, tokens):
        '''
        Tags the parts of speech in the given sentence.
        '''
        return nltk.pos_tag(tokens)