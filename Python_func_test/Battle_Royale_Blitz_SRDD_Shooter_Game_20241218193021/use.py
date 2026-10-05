def use(self, target):
        target.health -= self.damage
        print(f"{target.character.name} takes {self.damage} damage.")