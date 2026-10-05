def get_user_move(self):
        '''
        Get the user's move.
        '''
        try:
            move = input("Enter your move (e.g., 'rotate 1' or 'swap 1 2'): ").strip().lower()
            return move
        except Exception as e:
            print(f"Error in getting user move: {e}")
            return None