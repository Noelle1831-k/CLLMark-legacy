def boost(self):
        if not self.boost_active:
            self.boost_active = True
            self.speed = self.boost_speed