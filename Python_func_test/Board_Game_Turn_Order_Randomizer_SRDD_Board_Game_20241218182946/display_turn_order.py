def display_turn_order(turn_order):
    """
    Displays the randomized turn order to the user.
    Args:
        turn_order (list): A list of player names in the randomized order.
    """
    print('\nRandomized Turn Order:')
    for i, player in enumerate(turn_order, 1):
        print(f'{i}. {player}')