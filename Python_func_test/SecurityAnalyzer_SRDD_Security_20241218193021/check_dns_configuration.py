def check_dns_configuration(self):
        # Simulate DNS configuration check
        dns_servers = ["8.8.8.8", "8.8.4.4"]
        if not dns_servers:
            self.vulnerabilities.append("No DNS servers configured")