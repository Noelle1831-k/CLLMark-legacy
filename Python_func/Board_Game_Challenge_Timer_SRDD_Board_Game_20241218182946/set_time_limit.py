def set_time_limit(self, challenge_index, time_limit):
        '''
        Sets the time limit for a specific challenge.
        '''
        self.challenges[challenge_index].time_limit = time_limit