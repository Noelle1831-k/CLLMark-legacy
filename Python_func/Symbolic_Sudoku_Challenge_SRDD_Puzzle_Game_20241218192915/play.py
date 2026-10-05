def play(self):
        while not self.board.is_complete():
            move = self.ui.get_user_move()
            if self.board.is_valid_move(move):
                self.board.place_symbol(move)
                self.ui.display_board(self.board)
            else:
                self.ui.display_invalid_move_message()
            if self.ui.wants_hint():
                hint = self.solver.get_hint()
                self.ui.display_hint(hint)
        self.ui.display_congratulations_message()