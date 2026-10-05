def fire(self):
        if self.ammo > 0:
            print(f"Firing {self.weapon_type}")
            self.ammo -= 1
        else:
            print("Out of ammo! Reload!")