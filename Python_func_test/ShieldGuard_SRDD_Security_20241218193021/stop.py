def stop(self):
        self.ui.display("Stopping ShieldGuard...")
        self.monitor.stop_monitoring()
        self.ui.display("ShieldGuard stopped successfully.")