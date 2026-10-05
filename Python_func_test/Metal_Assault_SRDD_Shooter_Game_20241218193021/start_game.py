def start_game(self):
        self.level.load_level(1)
        while self.running:
            self.handle_input()
            self.update()
            self.render()