def end_game(self):
        if self.colony.is_self_sustaining():
            print("Congratulations! Your colony is thriving!")
        else:
            print("Game Over. Your colony did not survive.")