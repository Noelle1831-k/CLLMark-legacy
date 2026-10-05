def __init__(self):
        '''
        Initializes the ExplanationProvider.
        '''
        self.explanations = {
            'NN': 'Noun: A person, place, thing, or idea.',
            'VBZ': 'Verb: An action or state.',
            'DT': 'Determiner: A word that introduces a noun.',
            'JJ': 'Adjective: A word that describes a noun.',
            'IN': 'Preposition: A word that shows the relationship between a noun and another word.',
            'PRP': 'Pronoun: A word that takes the place of a noun.',
            'MD': 'Modal: A word that expresses necessity or possibility.',
            'RB': 'Adverb: A word that modifies a verb, adjective, or other adverb.',
            'CONJ': 'Conjunction: A word that connects clauses or sentences.'
        }