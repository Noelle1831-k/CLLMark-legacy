def generate_random_board(symbols, difficulty):
    '''
    Generate a random Sudoku board based on the given symbols and difficulty level.
    '''
    board = [[None for _ in range(9)] for _ in range(9)]
    fill_attempts = {'easy': 30, 'medium': 40, 'hard': 50}
    attempts = fill_attempts.get(difficulty, 30)
    for _ in range(attempts):
        row, col = random.randint(0, 8), random.randint(0, 8)
        if board[row][col] is None:
            symbol = random.choice(symbols)
            if is_valid_partial_board(board, row, col, symbol):
                board[row][col] = symbol
    return board