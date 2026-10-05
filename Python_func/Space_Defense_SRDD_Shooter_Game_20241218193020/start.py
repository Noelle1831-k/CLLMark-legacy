def start(self):
        while self.running:
            self.update()
            self.render()
            self.clock.tick(60)