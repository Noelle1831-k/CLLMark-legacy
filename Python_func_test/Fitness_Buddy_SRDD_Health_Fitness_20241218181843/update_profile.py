def update_profile(self, **kwargs):
        '''
        Update user profile with given keyword arguments.
        '''
        for key, value in kwargs.items():
            setattr(self, key, value)