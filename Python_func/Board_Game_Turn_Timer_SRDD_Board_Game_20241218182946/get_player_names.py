def get_player_names():
    '''
    Prompts the user to input player names.
    '''
    player_names = []
    while True:
        name = input("Enter player name (or press Enter to finish): ").strip()
        if not name:
            break
        player_names.append(name)
    return player_names