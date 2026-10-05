def take_damage(self, amount):
        self.health -= amount
        print(f'Player took {amount} damage, health is now {self.health}')