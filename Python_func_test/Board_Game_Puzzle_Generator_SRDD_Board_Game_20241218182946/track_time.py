def track_time(self):
        '''
        Track the time taken to solve the puzzle.
        '''
        self.timer.stop()
        elapsed_time = self.timer.get_elapsed_time()
        print(f"Time taken: {elapsed_time} seconds")