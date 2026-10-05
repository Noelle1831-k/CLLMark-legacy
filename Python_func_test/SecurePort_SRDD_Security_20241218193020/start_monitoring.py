def start_monitoring(self):
        '''
        Initiates the network monitoring process.
        '''
        self.logger.log_event("Network monitoring started.")
        while self.running:
            self.analyze_traffic()
            time.sleep(1)  # Sleep to reduce CPU usage