def update_status_effects(self):
        '''
        Update and process the effects of any active status effects on the monster.
        '''
        for effect in self.status_effects:
            if effect == "Burned":
                self.take_damage(5)
                print(f"{self.name} takes 5 damage from being burned!")
            elif effect == "Frozen":
                print(f"{self.name} is frozen and cannot act!")
        # Clear status effects after processing
        self.status_effects = []