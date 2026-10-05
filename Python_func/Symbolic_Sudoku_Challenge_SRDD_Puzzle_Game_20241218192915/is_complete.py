def is_complete(self):
        '''
        Check if the board is complete, i.e., no empty cells remain.
        '''
        return all(all(cell is not None for cell in row) for row in self.grid)