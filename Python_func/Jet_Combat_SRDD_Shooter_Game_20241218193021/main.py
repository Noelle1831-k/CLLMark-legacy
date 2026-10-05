def main():
    pygame.init()
    screen = pygame.display.set_mode((800, 600))
    pygame.display.set_caption("Aerial Dogfight")
    clock = pygame.time.Clock()
    game_engine = GameEngine(screen)
    game_engine.start_game(clock)