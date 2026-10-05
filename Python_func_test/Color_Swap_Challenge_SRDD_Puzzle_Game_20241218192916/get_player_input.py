def get_player_input(self):
        move = input("Enter your move (x1 y1 x2 y2): ")
        return tuple(map(int, move.split()))