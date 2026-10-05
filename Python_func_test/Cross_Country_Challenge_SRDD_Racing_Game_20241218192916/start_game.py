def start_game(self):
        while self.running:
            self.update()
            self.render()
            self.handle_input()