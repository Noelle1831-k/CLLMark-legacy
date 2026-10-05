def shoot(self):
        '''
        Creates a new projectile from the alien's current position with a small chance.
        '''
        if randint(0, 100) < 5:  # 5% chance to shoot
            return Projectile(self.x + self.width // 2, self.y, 1)
        return None