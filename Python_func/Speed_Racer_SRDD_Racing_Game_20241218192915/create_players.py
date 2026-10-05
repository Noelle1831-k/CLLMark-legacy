def create_players(self):
        # Create players and assign vehicles
        player1 = player.Player("Player1", vehicle.Vehicle("Speedster"))
        player2 = player.Player("Player2", vehicle.Vehicle("Thunderbolt"))
        self.players.append(player1)
        self.players.append(player2)