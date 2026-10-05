def start_game(self):
        self.level_manager.load_level(1)
        while self.running:
            self.handle_events()
            self.update_game()
            self.render_game()
            self.clock.tick(60)