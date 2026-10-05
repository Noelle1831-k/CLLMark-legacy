def check_collision(self, player):
        player_rect = pygame.Rect(player.position.x - player.size / 2, player.position.y - player.size / 2, player.size, player.size)
        return self.rect.colliderect(player_rect)