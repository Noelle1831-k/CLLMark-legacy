def display_board(self, board):
        for row in board.grid:
            print(' '.join(cell if cell else '.' for cell in row))