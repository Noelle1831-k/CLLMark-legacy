def resume(self):
        '''
        Resumes the countdown timer.
        '''
        print("\nTimer resumed.")
        self.pause_event.set()