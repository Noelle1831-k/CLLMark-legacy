def check_collisions(self):
        for enemy in self.enemies:
            if self.player.position == enemy.position:
                enemy.take_damage(25)