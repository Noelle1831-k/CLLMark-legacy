def generate_scale(self, root_note, scale_type):
        '''
        Generates the notes of the specified scale.
        '''
        if scale_type not in self.scales:
            raise ValueError("Invalid scale type")
        intervals = self.scales[scale_type]
        self.current_scale = [root_note]
        current_note = root_note
        for interval in intervals:
            current_note += interval
            self.current_scale.append(current_note)