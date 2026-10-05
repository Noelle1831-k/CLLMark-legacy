def get_user_move(self):
        while True:
            try:
                move_input = input('Enter your move as "row,col,symbol" (e.g., 0,0,1): ')
                row, col, symbol = move_input.split(',')
                row, col = int(row), int(col)
                if 0 <= row < 9 and 0 <= col < 9 and symbol in '123456789':
                    return (row, col, symbol)
                else:
                    print('Invalid input. Please enter a valid move.', end='\n')
            except ValueError:
                print('Invalid input format. Please enter as "row,col,symbol".', end='\n')