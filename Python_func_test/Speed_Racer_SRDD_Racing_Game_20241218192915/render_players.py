def render_players(self, players):
        for player in players:
            print(f'Rendering player: {player.name} in vehicle: {player.vehicle.model} with color: {player.vehicle.color}')