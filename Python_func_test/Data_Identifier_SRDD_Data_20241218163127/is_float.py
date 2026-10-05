def is_float(self, value):
        '''
        Check if a value is a float.
        '''
        try:
            float(value)
            return True
        except ValueError:
            return False