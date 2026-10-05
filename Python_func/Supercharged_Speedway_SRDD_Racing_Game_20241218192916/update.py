def update(self, player):
        # Continuously check active keys for smooth movement
        for key in self.active_keys:
            if key in self.key_map:
                action = self.key_map[key]
                if action == 'move_left':
                    player.position[0] -= player.speed
                elif action == 'move_right':
                    player.position[0] += player.speed
                elif action == 'move_up':
                    player.position[1] -= player.speed
                elif action == 'move_down':
                    player.position[1] += player.speed