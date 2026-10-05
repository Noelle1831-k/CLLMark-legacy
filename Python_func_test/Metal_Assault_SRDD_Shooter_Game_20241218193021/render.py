def render(self):
        self.graphics.draw_sprite(self.player.sprite, self.player.position)
        for enemy in self.enemies:
            self.graphics.draw_sprite(enemy.sprite, enemy.position)
        self.graphics.draw_text(f"Score: {self.score}", (10, 10))
        self.graphics.draw_text(f"Health: {self.player.health}", (10, 30))