def process_input(self, game):
        '''
        Processes all user inputs and game events.
        :param game: The game instance to interact with.
        '''
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game.running = False
            elif event.type == pygame.USEREVENT:
                game.player.handle_boost_end()
        keys = pygame.key.get_pressed()
        for key, action in self.key_bindings.items():
            if keys[key]:
                action(game.player)