def attack(self, monsters):
        for weap in self.weapons:
            weap.use(monsters)