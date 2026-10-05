def use_random_ability(self, target):
        '''
        Use a random ability on the target, applying its effects.
        '''
        if self.abilities:
            ability = random.choice(self.abilities)
            print(f"{self.name} uses {ability} on the target!")
            self.apply_ability_effect(ability, target)