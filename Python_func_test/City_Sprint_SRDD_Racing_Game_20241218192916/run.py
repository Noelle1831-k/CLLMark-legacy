def run(self):
        self.sound_engine.play_background_music()
        while self.running:
            self.handle_events()
            self.update()
            self.render()
            self.clock.tick(60)
        pygame.quit()