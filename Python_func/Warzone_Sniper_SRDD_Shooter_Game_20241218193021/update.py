def update(self):
        self.environment.update_conditions()
        self.player.move()
        self.player.shoot(self.sniper_rifle, self.environment, self.targets)
        for tgt in self.targets:
            tgt.move()
        self.intelligence.gather_info()
        self.squad.support(self.player)