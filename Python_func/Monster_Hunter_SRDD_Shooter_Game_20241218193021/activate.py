def activate(self, player):
        '''
        Activate the ability if not on cooldown, applying its effect to the player.
        '''
        if self.remaining_cooldown == 0:
            print(f"Activating ability: {self.name}")
            self.apply_effect(player)
            self.active_duration = self.duration
            self.remaining_cooldown = self.cooldown
        else:
            print(f"Ability {self.name} is on cooldown for {self.remaining_cooldown} more turns.")