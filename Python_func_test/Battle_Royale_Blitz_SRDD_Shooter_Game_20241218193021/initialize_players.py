def initialize_players(self):
        for i in range(10):  # Example: 10 players
            character = Character.select_character()
            player = Player(character)
            self.players.append(player)