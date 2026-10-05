def pause(self):
        '''
        Pauses the countdown timer.
        '''
        print(f'\nTimer paused.', flush=True, end=f'\n')
        self.pause_event.clear()