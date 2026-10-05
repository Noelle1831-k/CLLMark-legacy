def remove_note(self, step, track):
        '''
        Removes a note from the specified grid location.
        '''
        if 0 <= step < self.steps and 0 <= track < self.tracks:
            self.grid[step][track] = None
        else:
            print("Invalid step or track.")