def scan_network(self):
        self.identify_open_ports()
        self.check_firewall_settings()
        return self.vulnerabilities