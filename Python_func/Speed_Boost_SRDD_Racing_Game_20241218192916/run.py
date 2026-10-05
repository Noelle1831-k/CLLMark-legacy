def run(self):
        while self.running:
            self.input_handler.process_input(self)
            self.player.update()
            self.track.check_collisions(self.player)
            self.renderer.draw(self.player, self.track)
            self.clock.tick(60)
            pygame.display.flip()