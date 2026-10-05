def fire_weapon(self, weapon_type):
        if weapon_type in self.weapons:
            print(f"{self.model} fires {weapon_type}.")
        else:
            print(f"{weapon_type} not available.")