def attack(self, players):
        if self.weapons:
            target = random.choice(players)
            if target != self:
                weapon = random.choice(self.weapons)
                weapon.use(target)
                print(f"{self.character.name} attacks {target.character.name} with {weapon.name}.")
                # Check if the target's health is zero or below
                if target.health <= 0:
                    print(f"{target.character.name} has been eliminated.")