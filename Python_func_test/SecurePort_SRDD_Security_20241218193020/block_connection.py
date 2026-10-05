def block_connection(self):
        '''
        Blocks connections from unknown sources.
        '''
        # Simulate checking incoming connections
        unknown_source = "192.168.1.100"  # Example IP
        if unknown_source not in self.blocked_sources:
            self.blocked_sources.add(unknown_source)
            self.logger.log_event(f"Blocked connection from {unknown_source}")