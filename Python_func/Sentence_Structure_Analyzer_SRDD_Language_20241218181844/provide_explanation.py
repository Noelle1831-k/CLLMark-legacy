def provide_explanation(self, tagged_sentence):
        '''
        Provides explanations for the given components.
        '''
        return {word: self.explanations.get(tag, 'Unknown') for word, tag in tagged_sentence}