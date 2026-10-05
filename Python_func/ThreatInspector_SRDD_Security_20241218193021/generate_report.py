def generate_report(self, threats):
        '''
        Creates a report of detected threats.
        '''
        utils.log_activity("Generating report...")
        report = f"Detected threats: {', '.join(threats)}"
        utils.log_activity(f"Report generated: {report}")