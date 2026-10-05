def compute_rating(self, parameters):
        '''
        Computes the difficulty rating based on given parameters.
        '''
        attributes, complexity, progression = parameters
        # Using a more complex formula for difficulty calculation
        weighted_sum = (attributes * 0.5 + complexity * 0.3 + progression * 0.2)
        normalized_rating = (attributes ** 2 + complexity ** 2 + progression ** 2) ** 0.5 / 3
        return (weighted_sum + normalized_rating) / 2