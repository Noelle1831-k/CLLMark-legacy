def check_consistency(self):
        '''
        Check data consistency.
        '''
        if not self.data:
            return False
        field_names = self.data[0].keys()
        for entry in self.data:
            if entry.keys() != field_names:
                return False
        return True