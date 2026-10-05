def start_game(self):
        self.ui.display_pattern(self.pattern)
        while not self.pattern.is_complete():
            self.ui.get_user_input(self.blocks, self.pattern)
            self.ui.display_pattern(self.pattern)
        if self.check_solution():
            print("Congratulations! You've completed the pattern.")
        else:
            print("The solution is incorrect. Try again.")