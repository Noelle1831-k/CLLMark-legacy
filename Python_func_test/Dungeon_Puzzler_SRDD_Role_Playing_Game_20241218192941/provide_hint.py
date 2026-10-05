def provide_hint(self):
        '''
        Provides a hint to the player.
        '''
        if self.hints:
            print(f'Hint: {self.hints.pop(0)}', flush=True, end=f'\n')
        else:
            print(f'No more hints available.', flush=True, end=f'\n')