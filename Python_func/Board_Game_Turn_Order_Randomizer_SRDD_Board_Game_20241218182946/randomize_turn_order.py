def randomize_turn_order(player_names):
    """
    Randomizes the turn order for the given list of player names.
    Args:
        player_names (list): A list containing the names of the players.
    Returns:
        list: A randomized list of player names.
    """
    turn_order = TurnOrder(player_names)
    turn_order.randomize()
    return turn_order.get_turn_order()