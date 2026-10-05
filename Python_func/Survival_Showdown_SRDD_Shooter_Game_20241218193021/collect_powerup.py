def collect_powerup(self, powerup):
        self.powerups.append(powerup)
        powerup.activate()