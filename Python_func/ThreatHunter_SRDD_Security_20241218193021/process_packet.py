def process_packet(self, packet):
        if IP in packet:
            src_ip = packet[IP].src
            dst_ip = packet[IP].dst
            if TCP in packet:
                print(f"Captured TCP packet from {src_ip} to {dst_ip}")
            self.packet_logs.append(packet)