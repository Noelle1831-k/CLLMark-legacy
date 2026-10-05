def setup_players(self):
        for i in range(4):
            player = Player(f"Player{i+1}")
            player.choose_weapon(random.choice(self.weapons))
            self.players.append(player)