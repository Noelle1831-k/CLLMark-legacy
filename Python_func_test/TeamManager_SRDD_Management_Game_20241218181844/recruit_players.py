def recruit_players(self):
        for i in range(11):
            self.players.append(player.Player(f"Player {i+1}"))