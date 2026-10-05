def next_challenge(self):
        '''
        Moves to the next challenge when the time is up.
        '''
        self.current_challenge_index += 1
        self.start_timer()