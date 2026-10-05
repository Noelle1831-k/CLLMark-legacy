def get_progress_percentage(self):
        '''
        Returns the current progress as a percentage.
        '''
        return (self.current_amount / self.target_amount) * 100