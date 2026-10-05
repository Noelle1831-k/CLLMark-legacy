def start_game(self):
        """
        Starts the Block Puzzle Challenge game.
        """
        print("Welcome to the Block Puzzle Challenge!")
        while not self.grid.is_full():
            print(f"\n--- Level {self.current_level} ---")
            block = random_block()
            print("Your block:")
            self.print_block(block.get_shape())
            position = self.get_player_input()
            if not self.grid.place_block(block, position):
                print("Invalid move. Try again.")
                continue
            lines_cleared = self.grid.clear_lines()
            self.update_score(lines_cleared)
            print(f"Score: {self.score}")
        self.leaderboard.update_leaderboard(self.score)
        print("\nGame Over! Your final score:", self.score)
        print("Top Scores:")
        for idx, score in enumerate(self.leaderboard.get_top_scores(), start=1):
            print(f"{idx}. {score}")