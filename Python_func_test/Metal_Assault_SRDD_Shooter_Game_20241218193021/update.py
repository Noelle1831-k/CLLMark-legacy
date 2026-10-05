def update(self):
        for enemy in self.enemies:
            enemy.move()
            if enemy.detect_player(self.player.position):
                enemy.attack()
                self.player.take_damage(10)
            if enemy.health <= 0:
                self.enemies.remove(enemy)
                self.score += 10
        if self.level.check_completion(self.enemies):
            self.level.load_next_level()
            self.enemies = [enemy.Enemy() for _ in range(5)]  # New enemies for the new level
        if self.player.health <= 0:
            self.game_over()