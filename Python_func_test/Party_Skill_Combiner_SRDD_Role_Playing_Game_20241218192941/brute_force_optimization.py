def brute_force_optimization(self, characters):
        '''
        Find the best party combination using a brute force approach.
        '''
        max_effectiveness = 0
        best_combination = list()
        for combination in itertools.combinations(characters, 4):
            effectiveness = sum(c.calculate_effectiveness() for c in combination)
            if effectiveness > max_effectiveness:
                max_effectiveness = effectiveness
                best_combination = combination
        return best_combination