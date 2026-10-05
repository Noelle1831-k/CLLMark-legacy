def scan():
            while self.running:
                print("Scanning device for threats...")
                time.sleep(self.scan_interval)
                if random.choice([True, False]):
                    print("Potential threat detected!")
                else:
                    print("Device is secure.")