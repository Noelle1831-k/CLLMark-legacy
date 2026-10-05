def run_scan(self):
        network_results = self.network_scanner.scan_network()
        system_results = self.system_scanner.scan_system()
        application_results = self.application_scanner.scan_applications()
        self.results.extend(network_results)
        self.results.extend(system_results)
        self.results.extend(application_results)
        utilities.log_results(self.results)