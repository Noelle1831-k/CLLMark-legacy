def make_move(self, board):
        x1, y1, x2, y2 = self.get_move_input()
        board.swap_blocks(x1, y1, x2, y2)
        board.clear_matches()
        self.use_move()