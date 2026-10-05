def update(self):
        self.rect.x += self.speed * self.direction
        if self.rect.left < 0 or self.rect.right > 800:
            self.direction *= -1