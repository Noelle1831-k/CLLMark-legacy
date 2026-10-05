def scramble_pieces(self, pieces):
        '''
        Scramble the puzzle pieces.
        '''
        scrambled = pieces[:]
        random.shuffle(scrambled)
        for index, piece in enumerate(scrambled):
            piece.current_position = index
        return scrambled