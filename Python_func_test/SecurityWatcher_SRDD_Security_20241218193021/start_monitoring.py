def start_monitoring(self):
        while True:
            self.process_monitor.scan_processes()
            self.file_monitor.scan_files()
            self.log_monitor.scan_logs()
            self.system_health.check_system_health()
            time.sleep(5)