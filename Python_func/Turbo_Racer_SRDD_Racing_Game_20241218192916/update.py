def update(self, players, track):
        for player in players:
            player.move()
            self.check_collisions(player, track)