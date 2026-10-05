def start(self):
        '''
        Starts the timer.
        '''
        self.remaining_time = self.duration
        while self.remaining_time > 0:
            print(f"Time left: {self.remaining_time} seconds")
            time.sleep(1)
            self.tick()
        print("Time's up!")