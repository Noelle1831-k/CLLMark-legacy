def get_input(self, event, player):
        if event.type == pygame.KEYDOWN:
            self.active_keys.add(event.key)
            self.process_key_down(event.key, player)
        elif event.type == pygame.KEYUP:
            self.active_keys.discard(event.key)
            self.process_key_up(event.key, player)