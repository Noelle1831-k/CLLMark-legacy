def handle_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False
            elif event.type == pygame.MOUSEBUTTONDOWN:
                hit_target = self.player.shoot(event.pos, self.targets)
                if hit_target:
                    self.targets.remove(hit_target)
                    self.targets.append(Target(random_position()))