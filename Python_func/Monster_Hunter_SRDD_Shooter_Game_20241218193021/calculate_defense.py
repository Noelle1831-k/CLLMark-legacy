def calculate_defense(self):
        '''
        Calculate the monster's defense based on its type and level.
        '''
        base_defense = 5
        type_multiplier = {"Normal": 1, "Elite": 1.5, "Boss": 2}
        return int(base_defense * type_multiplier[self.monster_type] * self.level)