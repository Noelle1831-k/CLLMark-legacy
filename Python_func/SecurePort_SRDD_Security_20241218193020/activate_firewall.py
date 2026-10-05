def activate_firewall(self):
        '''
        Activates the firewall to block unauthorized connections.
        '''
        self.logger.log_event("Firewall activated.")
        while self.running:
            self.block_connection()
            time.sleep(1)  # Sleep to reduce CPU usage