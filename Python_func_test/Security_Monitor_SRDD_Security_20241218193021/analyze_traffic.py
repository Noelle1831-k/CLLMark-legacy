def analyze_traffic(self, packet):
        '''
        Analyzes a single network packet for suspicious data.
        '''
        self.packet_count += 1
        print(f"Analyzing packet {self.packet_count}: {packet}")
        # Simulate analysis logic
        if packet["protocol"] == "FTP" and packet["data_size"] > 5000:
            return {"type": "Suspicious Data Transfer", "packet": packet}
        elif packet["protocol"] == "SSH" and "192.168" not in packet["source_ip"]:
            return {"type": "Unauthorized Access Attempt", "packet": packet}
        else:
            return None