def apply_powerup(self, powerup):
        powerup.apply(self)
        if powerup.active:
            self.active_powerups.append(powerup)