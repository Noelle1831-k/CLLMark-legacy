def apply(self, spaceship):
        if self.type == 'health':
            spaceship.health += 20
        elif self.type == 'speed':
            spaceship.speed += 1
        elif self.type == 'weapon':
            spaceship.upgrade_weapon()