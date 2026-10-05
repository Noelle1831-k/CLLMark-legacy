def take_damage(self, amount):
        self.health -= amount
        if self.health <= 0:
            print("Alien is dead")