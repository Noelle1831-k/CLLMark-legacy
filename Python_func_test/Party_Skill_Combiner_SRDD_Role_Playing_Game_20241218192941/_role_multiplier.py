def _role_multiplier(self, stat):
        '''
        Determine the multiplier for a stat based on the character's role.
        '''
        role_multipliers = {
            'warrior': {'strength': 2, 'agility': 1, 'intelligence': 0.5},
            'mage': {'strength': 0.5, 'agility': 1, 'intelligence': 2},
            'rogue': {'strength': 1, 'agility': 2, 'intelligence': 1},
            'healer': {'strength': 0.5, 'agility': 0.5, 'intelligence': 2.5}
        }
        return role_multipliers.get(self.role, {}).get(stat, 1)