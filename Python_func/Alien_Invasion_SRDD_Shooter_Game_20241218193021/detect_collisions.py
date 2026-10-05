def detect_collisions(self, player, aliens):
        for alien in aliens:
            if self.check_collision(player, alien):
                player.take_damage(10)
                alien.take_damage(10)