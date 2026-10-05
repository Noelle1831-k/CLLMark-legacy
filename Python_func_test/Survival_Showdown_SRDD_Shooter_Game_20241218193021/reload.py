def reload(self):
        '''
        Reloads the weapon, resetting ammo count after a delay.
        '''
        if not self.is_reloading:
            self.is_reloading = True
            print(f"Reloading {self.name}... This will take {self.reload_time} seconds.")
            import time
            time.sleep(self.reload_time)
            self.current_ammo = self.ammo_capacity
            self.is_reloading = False
            print(f"{self.name} reloaded. Ammo is now full: {self.current_ammo}/{self.ammo_capacity}.")