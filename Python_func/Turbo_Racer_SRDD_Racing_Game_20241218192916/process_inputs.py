def process_inputs(self, players):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    for player in players:
                        player.apply_turbo()
                elif event.key == pygame.K_DOWN:
                    for player in players:
                        player.slow_down()
        return True