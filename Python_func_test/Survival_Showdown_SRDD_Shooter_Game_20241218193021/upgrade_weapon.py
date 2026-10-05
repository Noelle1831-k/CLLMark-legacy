def upgrade_weapon(self, additional_damage, additional_ammo):
        '''
        Upgrades the weapon by increasing its damage and ammo capacity.
        '''
        self.damage += additional_damage
        self.ammo_capacity += additional_ammo
        self.current_ammo = self.ammo_capacity
        print(f"{self.name} upgraded! New damage: {self.damage}, New ammo capacity: {self.ammo_capacity}.")