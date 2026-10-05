def display_timer(self, time_limit):
        '''
        Displays the countdown timer.
        '''
        while time_limit > 0:
            self.pause_event.wait()  # Wait if paused
            mins, secs = divmod(time_limit, 60)
            timer = '{:02d}:{:02d}'.format(mins, secs)
            print(f"Challenge {self.current_challenge_index + 1}: {timer}", end="\r")
            time.sleep(1)
            time_limit -= 1
        print("\nTime's up! Moving to the next challenge...")