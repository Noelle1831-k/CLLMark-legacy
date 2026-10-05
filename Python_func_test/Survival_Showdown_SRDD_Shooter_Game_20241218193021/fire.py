def fire(self):
        '''
        Fires the weapon, reducing ammo and dealing damage.
        '''
        if self.is_reloading:
            print(f"{self.name} is reloading. Cannot fire.")
            return
        if self.current_ammo > 0:
            self.current_ammo -= 1
            print(f"Fired {self.name}. Ammo left: {self.current_ammo}/{self.ammo_capacity}.")
            self.deal_damage()
        else:
            print(f"{self.name} is out of ammo. Reloading...")
            self.reload()