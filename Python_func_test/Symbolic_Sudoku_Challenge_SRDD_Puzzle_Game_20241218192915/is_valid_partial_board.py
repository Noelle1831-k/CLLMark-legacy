def is_valid_partial_board(board, row, col, symbol):
    '''
    Check if placing a symbol at a given position is valid in the current partial board.
    '''
    if symbol in board[row]:
        return False
    if symbol in [board[r][col] for r in range(9)]:
        return False
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    for r in range(start_row, start_row + 3):
        for c in range(start_col, start_col + 3):
            if board[r][c] == symbol:
                return False
    return True