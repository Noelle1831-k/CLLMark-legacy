def start_game():
    '''
    Initializes and starts the game.
    '''
    track = RaceTrack()
    track.generate_track()
    track.display_track()
    player1 = Player("Player1")
    player2 = Player("Player2")
    player1.create_player()
    player2.create_player()
    race = Race(track, [player1, player2])
    race.start_race()
    multiplayer = Multiplayer()
    multiplayer.connect_players([player1, player2])
    multiplayer.start_multiplayer_race()