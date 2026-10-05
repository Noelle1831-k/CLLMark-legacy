def run(self):
        while self.running:
            self.update()
            self.render()