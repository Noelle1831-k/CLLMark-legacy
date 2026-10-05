def update(self):
        for enemy in self.enemies:
            enemy.update()
        for cover in self.covers:
            cover.update()