def start_game(self):
        while self.running:
            self.handle_input()
            self.update()
            self.render()
            self.clock.tick(60)
        pygame.quit()