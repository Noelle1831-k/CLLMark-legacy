def update_game(self):
        for target in self.targets:
            target.move()
            if self.player.shoot(target):
                self.targets.remove(target)
        self.ui.render()
        if not self.targets:
            self.end_game()