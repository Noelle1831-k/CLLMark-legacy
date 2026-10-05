def activate_power_up(self, board):
        print("Power-up activated!")
        # Apply a random power-up effect
        effect = random.choice(['clear_row', 'clear_column'])
        if effect == 'clear_row':
            row = random.randint(0, 7)
            for x in range(8):
                board.board[x][row] = None
        elif effect == 'clear_column':
            col = random.randint(0, 7)
            for y in range(8):
                board.board[col][y] = None