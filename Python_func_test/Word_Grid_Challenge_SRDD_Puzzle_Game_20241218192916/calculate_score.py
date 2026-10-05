def calculate_score(self, words):
        '''
        Calculate score based on words found.
        '''
        score = 0
        for word in words:
            score += len(word) * 10
            if self.grid.is_special_word(word):
                score += 50
        return score