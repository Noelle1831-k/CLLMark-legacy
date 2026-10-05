def calculate_health(self):
        '''
        Calculate the monster's health based on its type and level.
        '''
        base_health = 50
        type_multiplier = {"Normal": 1, "Elite": 1.5, "Boss": 2}
        return int(base_health * type_multiplier[self.monster_type] * self.level)