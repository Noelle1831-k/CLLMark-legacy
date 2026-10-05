def move(self):
        self.rect.y += self.speed
        if self.rect.top > 600:
            self.rect.bottom = 0