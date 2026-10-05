def main():
    game = GameEngine()
    game.start_game()
    while not game.is_game_over():
        game.update_game_state()
    game.end_game()