def start(self):
        self.running = True
        threading.Thread(target=self._run).start()