def show_system_status(self, monitor_status, browsing_status):
        '''Display current system status.'''
        self.display("\n--- System Status ---")
        self.display(f"Real-Time Monitoring: {'Active' if monitor_status else 'Inactive'}")
        self.display(f"Secure Browsing: {'Enabled' if browsing_status else 'Disabled'}")
        self.display("----------------------")