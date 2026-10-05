def is_integer(self, value):
        '''
        Check if a value is an integer.
        '''
        try:
            int(value)
            return True
        except ValueError:
            return False