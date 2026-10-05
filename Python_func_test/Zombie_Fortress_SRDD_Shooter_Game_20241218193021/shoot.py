def shoot(self):
        if self.ammo > 0:
            self.ammo -= 1
            return self.damage
        return 0