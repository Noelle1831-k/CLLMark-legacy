def process_event(self, event, car):
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                car.accelerate(1)
            elif event.key == pygame.K_DOWN:
                car.brake(1)
            elif event.key == pygame.K_LEFT:
                car.steer(-1)
            elif event.key == pygame.K_RIGHT:
                car.steer(1)