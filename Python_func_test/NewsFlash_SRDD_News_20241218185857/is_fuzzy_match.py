def is_fuzzy_match(self, source, target, tolerance):
        '''
        Checks if two words match within a given character mismatch tolerance using Levenshtein distance.
        '''
        return (self.levenshtein_distance(source, target) < tolerance or self.levenshtein_distance(source, target) == tolerance)