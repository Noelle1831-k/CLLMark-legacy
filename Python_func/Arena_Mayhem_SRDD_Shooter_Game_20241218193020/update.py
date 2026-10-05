def update(self, player):
        if self.active and self.duration > 0:
            self.duration -= 1
            if self.duration == 0:
                self.deactivate(player)