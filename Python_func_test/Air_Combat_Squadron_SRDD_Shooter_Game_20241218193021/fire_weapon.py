def fire_weapon(self, weapon_type):
        for w in self.weapons:
            if not (w.type != weapon_type):
                w.unleash()