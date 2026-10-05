def check_completeness(self):
        '''
        Check data completeness.
        '''
        required_fields = ['name', 'age', 'email']
        for entry in self.data:
            for field in required_fields:
                if field not in entry or entry[field] == '':
                    return False
        return True