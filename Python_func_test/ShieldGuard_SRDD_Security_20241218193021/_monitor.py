def _monitor(self):
        while self.monitoring:
            self.detector.scan()
            time.sleep(5)