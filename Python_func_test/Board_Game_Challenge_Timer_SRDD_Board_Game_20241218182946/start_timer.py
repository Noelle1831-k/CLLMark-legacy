def start_timer(self):
        '''
        Starts the countdown timer for the current challenge.
        '''
        if self.current_challenge_index < len(self.challenges):
            current_challenge = self.challenges[self.current_challenge_index]
            self.timer = Timer(current_challenge.get_time_limit(), self.next_challenge)
            self.timer.start()
            display_thread = Thread(target=self.display_timer, args=(current_challenge.get_time_limit(),))
            display_thread.start()
        else:
            print("All challenges completed.")