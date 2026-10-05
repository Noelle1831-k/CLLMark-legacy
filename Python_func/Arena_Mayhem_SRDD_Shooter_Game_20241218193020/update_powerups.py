def update_powerups(self):
        for powerup in self.active_powerups:
            powerup.update(self)
        self.active_powerups = [p for p in self.active_powerups if p.active]