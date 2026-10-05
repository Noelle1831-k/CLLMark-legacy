def apply_status_effect(self, effect):
        '''
        Apply a status effect (e.g., "Burned", "Frozen") to the monster.
        '''
        if effect not in self.status_effects:
            self.status_effects.append(effect)
            print(f"{self.name} is now {effect}!")