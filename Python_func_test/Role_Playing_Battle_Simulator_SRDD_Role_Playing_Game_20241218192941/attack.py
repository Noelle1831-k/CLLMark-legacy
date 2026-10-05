def attack(self, target):
        damage = max(0, self.attack_power - target.defense)
        target.take_damage(damage)
        return damage