def use_boost(self):
        if self.boost_remaining > 0:
            self.position += self.boost
            self.boost_remaining -= 1