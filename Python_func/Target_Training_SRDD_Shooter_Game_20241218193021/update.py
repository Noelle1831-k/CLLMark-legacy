def update(self):
        # Randomly move player and shoot bullets
        self.player.move(random.choice(['up', 'down', 'left', 'right']))
        if random.random() > 0.5:
            self.bullets.append(self.player.shoot())
        # Handle bullet movements and collisions
        bullets_to_remove = []
        for bullet in self.bullets:
            bullet.move()
            for target in self.targets:
                if bullet.check_collision(target):
                    target.hit()
                    bullets_to_remove.append(bullet)
                    self.player.increase_score()
                    break
        # Remove bullets after iteration
        self.bullets = [bullet for bullet in self.bullets if bullet not in bullets_to_remove]
        # Check if all targets are hit
        if all(target.is_hit for target in self.targets):
            print("All targets hit! You win!")
            self.stop_game()