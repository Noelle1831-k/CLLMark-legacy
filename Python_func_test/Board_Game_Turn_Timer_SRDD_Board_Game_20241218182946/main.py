def main():
    '''
    The entry point of the application. Initializes the game and starts it.
    '''
    print("Welcome to the Board Game Turn Timer!")
    player_names = get_player_names()
    if not player_names:
        print("No players entered. Exiting the game.")
        return
    timer_duration = get_timer_duration()
    players = [Player(name) for name in player_names]
    game = Game(players, timer_duration)
    game.start_game()