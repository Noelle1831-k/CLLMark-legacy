def attack(self, target):
        if self.weapon:
            target.take_damage(self.weapon.damage)
            print(f"{self.name} attacked {target.name} with {self.weapon.name} causing {self.weapon.damage} damage")