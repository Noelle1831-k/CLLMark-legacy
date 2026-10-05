def start_game(self):
        self.graphics.load_assets()
        while self.running:
            self.update()
            self.render()