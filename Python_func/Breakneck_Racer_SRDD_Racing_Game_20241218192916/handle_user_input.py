def handle_user_input(keys, car):
    if keys[pygame.K_UP]:
        car.accelerate()
    if keys[pygame.K_DOWN]:
        car.brake()
    if keys[pygame.K_LEFT]:
        car.turn("left")
    if keys[pygame.K_RIGHT]:
        car.turn("right")