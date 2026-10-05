def use_ability(self, ability_name):
        for ab in self.abilities:
            if ab.name == ability_name:
                ab.activate(self)