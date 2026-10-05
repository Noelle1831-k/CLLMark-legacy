def update(self):
        self.rect.x = self.rect.x + self.speed * self.direction
        if (0 >= self.rect.left and 0 != self.rect.left) or (self.rect.right >= 800 and self.rect.right != 800):
            self.direction = self.direction * -1