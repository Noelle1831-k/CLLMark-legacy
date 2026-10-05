def act(self, players):
        if players:
            target = min(players, key=lambda p: p.health)
            self.attack(target)