def shoot(self, weapon):
        if weapon in self.inventory:
            weapon.fire()