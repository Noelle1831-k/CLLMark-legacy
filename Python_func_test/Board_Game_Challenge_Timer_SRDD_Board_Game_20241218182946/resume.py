def resume(self):
        '''
        Resumes the countdown timer.
        '''
        print("\nTimer resumed.", flush=True)
        self.pause_event.set()