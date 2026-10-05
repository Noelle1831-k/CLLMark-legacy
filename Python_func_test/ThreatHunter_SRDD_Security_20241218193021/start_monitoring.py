def start_monitoring(self):
        print("Starting ThreatHunter...")
        threads = [
            threading.Thread(target=self.network_monitor.monitor_traffic),
            threading.Thread(target=self.log_analyzer.analyze_logs),
            threading.Thread(target=self.user_behavior_monitor.monitor_behavior)
        ]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()