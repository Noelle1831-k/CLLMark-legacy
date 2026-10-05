def deactivate_boost(self):
        if self.boost_active:
            self.boost_active = False
            self.speed = min(self.speed, self.max_speed)