def draw_car(self, car):
        pygame.draw.rect(self.screen, car.color, (*car.position, 20, 10))