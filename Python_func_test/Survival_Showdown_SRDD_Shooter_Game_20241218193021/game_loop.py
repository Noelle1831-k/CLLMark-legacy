def game_loop(self):
        while self.running:
            self.player.move()
            self.player.shoot()
            for enemy in self.enemies:
                enemy.move()
                enemy.attack()
            self.arena.shrink()
            self.score.update_score()
            if not self.running:
                self.end_game()