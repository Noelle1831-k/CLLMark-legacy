def get_player_input(self):
        """
        Gets and validates player input for block placement.
        """
        while True:
            try:
                position = input("Enter the row and column (e.g., '2,3') to place the block: ")
                row, col = map(int, position.split(','))
                return row, col
            except ValueError:
                print("Invalid input format. Please enter row and column separated by a comma.")