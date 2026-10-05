def get_player_names(num_players):
    """
    Collects player names from the user based on the number of players.
    Args:
        num_players (int): The number of players participating in the game.
    Returns:
        list: A list containing the names of the players.
    """
    player_names = []
    for i in range(1, num_players + 1):
        name = input(f"Enter the name of Player {i}: ").strip()
        while not name:
            print("Name cannot be empty.")
            name = input(f"Enter the name of Player {i}: ").strip()
        player_names.append(name)
    return player_names