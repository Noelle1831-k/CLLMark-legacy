def __del__(self):
        '''
        Destructor for the FileHandler class to ensure cleanup is performed.
        '''
        self.cleanup()