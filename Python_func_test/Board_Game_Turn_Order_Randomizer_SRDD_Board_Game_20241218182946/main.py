def main():
    """
    Main function to handle the user interface and flow of the application.
    Collects input, randomizes turn order, and displays the result.
    """
    print("Welcome to the Board Game Turn Order Randomizer!\n")
    try:
        num_players = int(input("Enter the number of players: "))
        if num_players < 2:
            raise ValueError("The number of players must be at least 2.")
    except ValueError as e:
        display_error(f"Invalid input for number of players: {e}")
        return
    player_names = get_player_names(num_players)
    turn_order = randomize_turn_order(player_names)
    display_turn_order(turn_order)