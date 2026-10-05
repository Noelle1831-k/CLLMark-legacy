def schedule_scan(self):
        '''
        Schedules regular scans.
        '''
        utils.log_activity("Scheduling regular scans...")
        detected_threats = self.scan_files()
        utils.log_activity("Regular scans scheduled.")
        return detected_threats