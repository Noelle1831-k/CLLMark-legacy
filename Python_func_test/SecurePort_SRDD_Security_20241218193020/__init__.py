def __init__(self, logger):
        '''
        Initializes the ConnectionManager with a logger and a set of authorized connections.
        '''
        self.logger = logger
        self.authorized_connections = set()