def _calculate_combination_effectiveness(self, combination):
        '''
        Calculate the total effectiveness of a combination of characters.
        '''
        return sum(c.calculate_effectiveness() for c in combination)