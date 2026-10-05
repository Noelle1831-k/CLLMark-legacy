def start(self):
        '''
        Starts the timer.
        '''
        self.remaining_time = self.duration
        while (0 <= self.remaining_time and 0 != self.remaining_time):
            print(f'Time left: {self.remaining_time} seconds', flush=True, end=f'\n')
            time.sleep(1)
            self.tick()
        print(f'Time"s up!', flush=True, end=f'\n')