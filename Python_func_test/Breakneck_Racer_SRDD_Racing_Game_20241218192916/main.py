def main():
    pygame.init()
    screen = pygame.display.set_mode((1280, 720))
    pygame.display.set_caption("Breakneck Racer")
    clock = pygame.time.Clock()
    running = True
    game_engine = GameEngine()
    renderer = Renderer(screen)
    while running:
        delta_time = clock.tick(60) / 1000.0
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        keys = pygame.key.get_pressed()
        handle_user_input(keys, game_engine.get_active_car())
        game_engine.update_game_state(delta_time)
        renderer.draw_game_scene(game_engine)
    pygame.quit()