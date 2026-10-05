def start(self):
        self.ui.clear_screen()
        self.ui.display("Starting ShieldGuard...")
        self.monitor.start_monitoring()
        self.browser.enable_protection()
        self.ui.run(self)
        self.stop()