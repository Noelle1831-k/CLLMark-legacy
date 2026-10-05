def shoot(self):
        bullet = pygame.Vector2(self.position.x, self.position.y)
        self.bullets.append(bullet)
        print("Player shoots a bullet")