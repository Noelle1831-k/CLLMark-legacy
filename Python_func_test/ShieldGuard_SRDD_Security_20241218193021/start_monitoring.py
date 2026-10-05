def start_monitoring(self):
        self.monitoring = True
        threading.Thread(target=self._monitor, daemon=True).start()