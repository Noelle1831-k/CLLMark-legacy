def process_input(self, car):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    car.accelerate(0.1)
                elif event.key == pygame.K_DOWN:
                    car.accelerate(-0.1)
                elif event.key == pygame.K_LEFT:
                    car.steer(-0.05)
                elif event.key == pygame.K_RIGHT:
                    car.steer(0.05)