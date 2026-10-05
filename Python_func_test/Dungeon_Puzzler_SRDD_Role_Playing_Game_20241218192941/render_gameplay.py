def render_gameplay(dungeon, player):
    '''
    Renders the current state of the game.
    '''
    print("\nCurrent Room:")
    print(f"Player Position: {player.position}")
    print(f"Room Contents: {dungeon.layout[player.position[0]][player.position[1]]}")
    print()