def __init__(self, track, players):
        '''
        Initializes a race with a track and players.
        '''
        self.track = track
        self.players = players
        self.player_positions = {player.name: 0 for player in players}
        self.race_status = "Not Started"