def update_game_state(self):
        for player in self.players:
            player.move(random.choice(["up", "down", "left", "right"]))
            if random.random() > 0.5:
                player.attack(random.choice(self.npcs))
            player.update_powerups()
        for npc in self.npcs:
            npc.act(self.players)