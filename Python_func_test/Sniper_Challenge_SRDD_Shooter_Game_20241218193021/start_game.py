def start_game(self):
        self.ui.render()
        while self.running:
            self.update_game()