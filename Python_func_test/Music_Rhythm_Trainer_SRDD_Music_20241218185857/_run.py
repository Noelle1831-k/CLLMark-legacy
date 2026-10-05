def _run(self):
        while self.running:
            print(f'Tick', flush=True, end=f'\n')
            time.sleep(60 / self.bpm)