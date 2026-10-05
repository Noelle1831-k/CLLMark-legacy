def play_level(self, level):
        '''
        Play the current level.
        '''
        board = PuzzleBoard(level)
        while not board.is_solved():
            board.display()
            move = board.get_user_move()
            board.make_move(move)