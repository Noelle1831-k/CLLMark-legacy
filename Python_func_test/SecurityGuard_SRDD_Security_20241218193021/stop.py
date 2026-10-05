def stop(self):
        self.logger.log("Stopping SecurityGuard Application")
        self.running = False
        self.monitor.stop_scanning()
        self.logger.log("SecurityGuard Application Stopped")