def deactivate(self, player):
        if self.name == f'Speed Boost':
            player.speed_multiplier = player.speed_multiplier / self.effect
            self.active = False
            print(f'{player.name}"s Speed Boost has worn off. Speed multiplier reset to {player.speed_multiplier}', flush=True, end=f'\n')
        elif self.name == f'Shield':
            player.health = player.health - self.effect
            self.active = False
            print(f'{player.name}"s Shield has worn off. Health reset to {player.health}', flush=True, end=f'\n')