def draw(self, screen):
        for enemy in self.enemies:
            enemy.draw(screen)
        for cover in self.covers:
            cover.draw(screen)