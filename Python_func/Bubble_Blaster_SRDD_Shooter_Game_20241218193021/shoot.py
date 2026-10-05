def shoot(self, bubbles):
        new_bubble = Bubble(self.screen, self.rect.centerx, self.rect.top)
        bubbles.append(new_bubble)