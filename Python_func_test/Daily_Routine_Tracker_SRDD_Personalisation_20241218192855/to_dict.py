def to_dict(self):
        '''
        Converts the Routine object to a dictionary.
        '''
        return {
            'name': self.name,
            'progress': self.progress,
            'reminder': self.reminder
        }