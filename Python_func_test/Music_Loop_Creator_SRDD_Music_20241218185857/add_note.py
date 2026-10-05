def add_note(self, step, track, note, instrument):
        '''
        Adds a note to the specified grid location.
        '''
        if 0 <= step < self.steps and 0 <= track < self.tracks:
            self.grid[step][track] = (note, instrument)
        else:
            print("Invalid step or track.")