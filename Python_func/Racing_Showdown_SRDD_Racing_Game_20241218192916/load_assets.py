def load_assets(self, player: Player, ai_opponents: list, racetrack: RaceTrack):
        # Load and initialize assets
        self.player_sprite = pygame.Surface((50, 30))
        self.player_sprite.fill((0, 255, 0))  # Green color for player vehicle
        for ai in ai_opponents:
            ai_sprite = pygame.Surface((50, 30))
            ai_sprite.fill((255, 0, 0))  # Red color for AI vehicles
            self.ai_sprites.append(ai_sprite)
        self.track = racetrack