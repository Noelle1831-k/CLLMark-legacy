def update(self):
        while self.is_running:
            for player in self.players[:]:  # Iterate over a copy of the list
                player.move()
                player.scavenge()
                player.attack(self.players)
                # Remove players with zero or negative health
                if player.health <= 0:
                    print(f"{player.character.name} has been eliminated.")
                    self.players.remove(player)
            self.arena.shrink()
            if len(self.players) <= 1:
                self.end_game()