def process_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False