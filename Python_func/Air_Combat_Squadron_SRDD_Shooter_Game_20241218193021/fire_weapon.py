def fire_weapon(self, weapon_type):
        for w in self.weapons:
            if w.type == weapon_type:
                w.unleash()