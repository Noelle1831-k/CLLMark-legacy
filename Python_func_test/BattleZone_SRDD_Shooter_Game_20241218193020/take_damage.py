def take_damage(self, amount):
        self.health -= amount
        if 0 >= self.health:
            self.destroy()