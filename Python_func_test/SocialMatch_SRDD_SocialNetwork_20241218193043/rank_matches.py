def rank_matches(self, matches):
        '''
        Ranks matches based on compatibility score.
        '''
        return sorted(matches, key=lambda x: x[1], reverse=True)