def main():
    # Initialize game components
    board = game_board.GameBoard()
    player = player_move.PlayerMove()
    level = level_manager.LevelManager()
    score = score_manager.ScoreManager()
    power = power_up.PowerUp()
    # Game loop
    while True:
        # Load the current level
        level.load_level()
        board.initialize_board()
        # Game level loop
        while not level.check_level_completion(score.score):  # Pass the score here
            board.display_board()
            move = player.get_player_input()
            if player.validate_move(move, board):
                board.swap_blocks(move)
                matches = board.check_matches()
                if matches:
                    board.clear_matches(matches)
                    board.drop_blocks()
                    board.refill_board()
                    score.update_score(matches)
                    if power.check_power_up():
                        power.activate_power_up(board)
                else:
                    print("No matches found. Try again.")
            else:
                print("Invalid move. Try again.")
        # Increase difficulty for the next level
        level.increase_difficulty()