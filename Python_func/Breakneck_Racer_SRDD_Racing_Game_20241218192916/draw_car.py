def draw_car(self, car):
        car_color = (255, 0, 0)
        car_rect = pygame.Rect(car.position[0], car.position[1], 50, 100)
        pygame.draw.rect(self.screen, car_color, car_rect)