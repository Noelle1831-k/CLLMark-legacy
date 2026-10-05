def stop_timer(self):
        if self.start_time:
            elapsed_time = time.time() - self.start_time
            print(f"Timer stopped. Elapsed time: {elapsed_time} seconds.")
        else:
            print("Timer not started yet.")