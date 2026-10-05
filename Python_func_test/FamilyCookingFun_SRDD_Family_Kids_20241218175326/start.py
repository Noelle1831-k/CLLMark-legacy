def start(self, duration):
        self.timers.append(duration)
        timer_thread = threading.Thread(target=self.run_timer, args=(duration,))
        timer_thread.start()