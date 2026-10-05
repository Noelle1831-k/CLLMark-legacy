def main():
    ui = UserInterface()
    game = SudokuGame(ui)
    game.start()