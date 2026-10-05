def get_elapsed_time(self):
        '''
        Get the elapsed time between start and stop.
        '''
        if self.start_time is None or self.end_time is None:
            return 0
        return self.end_time - self.start_time