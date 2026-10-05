def __init__(self, vehicle):
        self.vehicle = vehicle
        self.score = 0
        self.controls = {
            'accelerate': pygame.K_UP,
            'brake': pygame.K_DOWN,
            'turn_left': pygame.K_LEFT,
            'turn_right': pygame.K_RIGHT
        }