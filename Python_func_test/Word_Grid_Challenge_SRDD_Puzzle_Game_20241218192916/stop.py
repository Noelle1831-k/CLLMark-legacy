def stop(self):
        '''
        Stop the timer and print elapsed time.
        '''
        self.end_time = time.time()
        elapsed = self.end_time - self.start_time
        print(f"Time taken: {elapsed:.2f} seconds")