def process_input(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.is_running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    self.player_jet.maneuver("left")
                elif event.key == pygame.K_RIGHT:
                    self.player_jet.maneuver("right")
                elif event.key == pygame.K_SPACE:
                    self.player_jet.fire_weapon("Missile")