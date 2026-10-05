def provide_hint(self):
        '''
        Provides a hint to the player.
        '''
        if self.hints:
            print(f"Hint: {self.hints.pop(0)}")
        else:
            print("No more hints available.")