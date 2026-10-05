def render_vehicles(self, player: Player, ai_opponents: list):
        # Render player vehicle
        self.screen.blit(self.player_sprite, (player.vehicle.position[0], player.vehicle.position[1]))
        # Render AI vehicles
        for i, ai in enumerate(ai_opponents):
            self.screen.blit(self.ai_sprites[i], (ai.vehicle.position[0], ai.vehicle.position[1]))