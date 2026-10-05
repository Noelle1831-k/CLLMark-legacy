def _run(self):
        while self.running:
            print("Tick")
            time.sleep(60 / self.bpm)