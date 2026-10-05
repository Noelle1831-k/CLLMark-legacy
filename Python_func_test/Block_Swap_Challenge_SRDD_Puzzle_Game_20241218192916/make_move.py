def make_move(self, board):
        # Prompt user for input
        try:
            x1, y1 = map(int, input("Enter the coordinates of the first block to swap (x1 y1): ").split())
            x2, y2 = map(int, input("Enter the coordinates of the second block to swap (x2 y2): ").split())
            if board.is_adjacent(x1, y1, x2, y2):
                board.swap_blocks(x1, y1, x2, y2)
            else:
                print("Blocks are not adjacent. Try again.")
                self.make_move(board)
        except ValueError:
            print("Invalid input. Please enter integer coordinates.")
            self.make_move(board)