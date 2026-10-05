def check_time(self):
        elapsed = time.time() - self.start_time
        return max(0, self.limit - elapsed)