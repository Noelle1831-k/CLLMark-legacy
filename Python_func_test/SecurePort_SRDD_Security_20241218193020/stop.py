def stop(self):
        '''
        Stops the network monitoring process.
        '''
        self.running = False
        self.logger.log_event("Network monitoring stopped.")