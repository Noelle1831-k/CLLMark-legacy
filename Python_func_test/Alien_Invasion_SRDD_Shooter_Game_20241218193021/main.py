def main():
    pygame.init()
    screen = pygame.display.set_mode((800, 600))
    pygame.display.set_caption("Alien Invasion")
    game = Game(screen)
    game.start_game()