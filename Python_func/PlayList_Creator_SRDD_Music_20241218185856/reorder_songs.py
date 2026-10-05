def reorder_songs(self, new_order):
        '''
        Reorders the songs in the playlist based on a new order.
        '''
        self.songs = [self.songs[i] for i in new_order if i < len(self.songs)]