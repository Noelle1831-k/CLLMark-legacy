def scout_players(self):
        name = random.choice(self.names)
        player = Player(name)
        print(f"Scouted new player: {player.display_stats()}")
        return player