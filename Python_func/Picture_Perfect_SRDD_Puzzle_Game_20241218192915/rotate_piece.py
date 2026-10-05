def rotate_piece(self, piece_index):
        '''
        Rotate a specific puzzle piece.
        '''
        if 0 <= piece_index < len(self.arrangement):
            piece = self.arrangement[piece_index]
            piece.rotate()  # Use the new rotate method
            print(f"Rotated piece at index {piece_index}.")
            self.moves_made += 1
        else:
            print("Invalid piece index.")