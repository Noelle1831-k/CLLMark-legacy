def monitor_browsing_activity(self):
        print("Monitoring browsing activity...")
        # Simulate browsing activity
        urls = ["http://example.com", "http://phishing.com"]
        for url in urls:
            threat_level = self.phishing_detector.scan_url(url)
            self.alert_system.display_real_time_indicator(url, threat_level)