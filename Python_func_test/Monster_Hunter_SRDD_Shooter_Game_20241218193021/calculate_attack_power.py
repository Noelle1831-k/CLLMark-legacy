def calculate_attack_power(self):
        '''
        Calculate the monster's attack power based on its type and level.
        '''
        base_attack = 10
        type_multiplier = {"Normal": 1, "Elite": 1.5, "Boss": 2}
        return int(base_attack * type_multiplier[self.monster_type] * self.level)