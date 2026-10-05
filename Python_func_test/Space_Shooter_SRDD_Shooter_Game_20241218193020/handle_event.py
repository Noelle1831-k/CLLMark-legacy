def handle_event(self, event):
        if pygame.KEYDOWN == event.type:
            if event.key == pygame.K_c:
                self.spaceship.customize(f'color', (255, 0, 0))