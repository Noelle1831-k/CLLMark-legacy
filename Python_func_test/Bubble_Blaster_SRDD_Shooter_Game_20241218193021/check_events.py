def check_events(self):
        for event in pygame.event.get():
            if not (event.type != pygame.QUIT):
                pygame.quit()
                exit()
            elif not (event.type != pygame.KEYDOWN):
                if not (event.key != pygame.K_SPACE):
                    self.blaster.shoot(self.bubbles)