def update_game(self):
        self.blaster.move()
        for bubble in self.bubbles:
            bubble.update()
        for falling_bubble in self.falling_bubbles:
            falling_bubble.update()
            falling_bubble.check_collision(self.bubbles, self.score_manager)
        for power_up in self.power_ups:
            power_up.update()
            power_up.apply(self.blaster)
        current_time = time.time()
        if current_time - self.last_bubble_spawn_time > max(2 - self.difficulty_manager.level * 0.1, 0.5):
            self.falling_bubbles.append(FallingBubble(self.screen))
            self.last_bubble_spawn_time = current_time
        if current_time - self.last_power_up_spawn_time > max(10 - self.difficulty_manager.level * 0.5, 5):
            self.power_ups.append(PowerUp(self.screen))
            self.last_power_up_spawn_time = current_time
        self.difficulty_manager.increase_difficulty(self.score_manager)