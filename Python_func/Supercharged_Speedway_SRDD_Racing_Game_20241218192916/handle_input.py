def handle_input(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False
            self.input_handler.get_input(event, self.player)
        self.input_handler.update(self.player)