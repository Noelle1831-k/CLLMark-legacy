def process_input(self, player_car, stop_game_callback):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                stop_game_callback()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    player_car.speed = min(player_car.speed + 0.1, player_car.max_speed)
                elif event.key == pygame.K_DOWN:
                    player_car.speed = max(player_car.speed - 0.1, 0)
                elif event.key == pygame.K_LEFT:
                    player_car.x -= player_car.handling * player_car.speed
                elif event.key == pygame.K_RIGHT:
                    player_car.x += player_car.handling * player_car.speed