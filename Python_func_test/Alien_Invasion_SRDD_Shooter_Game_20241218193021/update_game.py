def update_game(self):
        self.player.move()
        for alien in self.aliens:
            alien.move()
        self.collision_manager.detect_collisions(self.player, self.aliens)