def run(self):
        while self.running:
            self.process_events()
            self.update()
            self.render()
            self.clock.tick(60)
        self.graphics_renderer.quit()