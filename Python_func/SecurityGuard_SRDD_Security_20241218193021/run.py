def run(self):
        self.logger.log("SecurityGuard Application Started")
        monitor_thread = threading.Thread(target=self.monitor.scan_device)
        monitor_thread.start()
        try:
            while self.running:
                threats = self.threat_detector.detect_threats()
                for threat in threats:
                    self.threat_detector.neutralize_threat(threat)
                self.secure_browser.filter_content()
                self.logger.log("SecurityGuard Application Running")
                time.sleep(10)  # Main loop interval
        except KeyboardInterrupt:
            self.stop()