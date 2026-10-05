def switch_weapon(self, new_weapon):
        '''
        Switches the current weapon to a new weapon.
        '''
        print(f"Switching from {self.name} to {new_weapon.name}.")
        self.name = new_weapon.name
        self.damage = new_weapon.damage
        self.ammo_capacity = new_weapon.ammo_capacity
        self.current_ammo = new_weapon.ammo_capacity
        self.reload_time = new_weapon.reload_time
        self.is_reloading = False