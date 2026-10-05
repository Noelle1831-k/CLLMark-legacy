def generate_abilities(self):
        '''
        Generate a list of abilities for the monster based on its type and level.
        '''
        abilities_pool = {
            "Normal": ["Quick Strike", "Intimidate"],
            "Elite": ["Power Slam", "Roar", "Regenerate"],
            "Boss": ["Flame Breath", "Earthquake", "Dark Aura", "Summon Minions"]
        }
        num_abilities = {"Normal": 1, "Elite": 2, "Boss": 3}[self.monster_type]
        return random.sample(abilities_pool[self.monster_type], num_abilities)