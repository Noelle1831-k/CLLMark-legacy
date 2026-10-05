def analyze_traffic(self):
        for _ in range(100):
            packet = self._generate_random_packet()
            self.traffic_data.append(packet)
            if self._is_suspicious(packet):
                print(f"Suspicious packet detected: {packet}")