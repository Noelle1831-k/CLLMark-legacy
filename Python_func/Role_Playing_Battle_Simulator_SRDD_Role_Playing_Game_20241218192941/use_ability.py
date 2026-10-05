def use_ability(self, ability_name, target):
        for ability in self.abilities:
            if ability.name == ability_name:
                return ability.use(self, target)
        return None