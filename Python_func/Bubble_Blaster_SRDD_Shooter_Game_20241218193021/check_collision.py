def check_collision(self, bubbles, score_manager):
        for bubble in bubbles:
            if self.rect.colliderect(bubble.rect):
                bubbles.remove(bubble)
                score_manager.update_score(10)