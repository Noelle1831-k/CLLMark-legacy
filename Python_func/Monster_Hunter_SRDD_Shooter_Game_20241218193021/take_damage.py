def take_damage(self, amount):
        if self.armor:
            amount -= self.armor.defense
        self.health -= max(amount, 0)