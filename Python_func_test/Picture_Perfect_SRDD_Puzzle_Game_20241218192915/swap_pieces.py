def swap_pieces(self, index1, index2):
        '''
        Swap two puzzle pieces.
        '''
        if 0 <= index1 < len(self.arrangement) and 0 <= index2 < len(self.arrangement):
            self.arrangement[index1], self.arrangement[index2] = self.arrangement[index2], self.arrangement[index1]
            print(f"Swapped pieces at indices {index1} and {index2}.")
            self.moves_made += 1
        else:
            print("Invalid indices for swapping.")