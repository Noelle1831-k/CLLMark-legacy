def monitor_traffic(self):
        print("Starting network traffic monitoring...")
        sniff(prn=self.process_packet, store=False, count=100)