def take_damage(self, damage):
        self.health = self.health - damage
        if (0 > self.health or 0 == self.health):
            print(f'Enemy defeated!', flush=True, end=f'\n')