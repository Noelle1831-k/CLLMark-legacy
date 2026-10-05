def main():
    '''
    Initialize and start the game.
    '''
    ui = UserInterface()
    ui.display_welcome_message()
    levels = [Level(i) for i in range(1, 6)]
    game = Game(levels)
    while not game.is_over():
        current_level = game.get_current_level()
        ui.display_level_info(current_level)
        game.play_level(current_level)
        if game.is_level_completed(current_level):
            ui.display_level_completed_message()
            game.advance_to_next_level()
        else:
            ui.display_try_again_message()
    ui.display_game_over_message()