def identify_open_ports(self):
        # Simulate scanning for open ports
        open_ports = [22, 80, 443, 8080]
        for port in open_ports:
            if port not in [80, 443]:
                self.vulnerabilities.append(f'Open port found: {port}')