def stop_profiling(self):
        self.end_time = time.time()
        print("Profiling stopped.")
        self._record_data()