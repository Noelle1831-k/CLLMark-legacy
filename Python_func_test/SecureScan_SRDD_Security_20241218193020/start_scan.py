def start_scan(self, scan_type='on-demand'):
        if scan_type == 'scheduled':
            self.scheduler.execute_scheduled_scans()
        else:
            self.scanner.scan_files()
            self.scanner.scan_applications()
            self.integrity_checker.check_integrity()