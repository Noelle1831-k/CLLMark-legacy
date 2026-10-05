def calculate_effectiveness(self):
        '''
        Calculate the overall effectiveness of a character based on their role and stats.
        '''
        effectiveness = 0
        for stat, value in self.stats.items():
            effectiveness += value * self._role_multiplier(stat)
        return effectiveness