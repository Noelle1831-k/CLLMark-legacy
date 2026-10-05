def take_damage(self, damage):
        self.health -= damage
        if self.health < 0:
            self.health = 0