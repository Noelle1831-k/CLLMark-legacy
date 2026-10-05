def check_game_over(self):
        return self.moves <= 0 or self.board.is_cleared() or not self.board.has_possible_moves()