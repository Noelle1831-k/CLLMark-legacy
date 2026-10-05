def boost(self):
        if not self.boosting:
            self.boosting = True
            self.speed += self.boost_speed
            pygame.time.set_timer(pygame.USEREVENT, 1000)