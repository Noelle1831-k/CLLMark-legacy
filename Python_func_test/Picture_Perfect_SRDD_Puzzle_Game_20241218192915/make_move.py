def make_move(self, move):
        '''
        Make a move on the board.
        '''
        if move is None:
            return
        parts = move.split()
        if len(parts) == 2 and parts[0] == 'rotate':
            self.rotate_piece(int(parts[1]))
        elif len(parts) == 3 and parts[0] == 'swap':
            self.swap_pieces(int(parts[1]), int(parts[2]))
        else:
            print('Invalid move format. Please try again.', end='\n')