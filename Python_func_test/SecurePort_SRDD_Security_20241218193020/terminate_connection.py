def terminate_connection(self, connection):
        '''
        Terminates unauthorized connections.
        '''
        if connection not in self.authorized_connections:
            self.logger.log_event(f"Terminating connection: {connection}")