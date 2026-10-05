def apply(self, blaster):
        if self.rect.colliderect(blaster.rect):
            self.active = True
            blaster.speed += 2