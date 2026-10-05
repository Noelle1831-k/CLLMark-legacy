def balance_roles(self):
        # Balance roles within the party
        role_count = {"Tank": 0, "DPS": 0, "Support": 0}
        for char in self.characters:
            if char.class_type == "Fighter":
                role_count["Tank"] += 1
            elif char.class_type == "Ranger":
                role_count["DPS"] += 1
            elif char.class_type == "Sorcerer":
                role_count["Support"] += 1
        self.roles = role_count