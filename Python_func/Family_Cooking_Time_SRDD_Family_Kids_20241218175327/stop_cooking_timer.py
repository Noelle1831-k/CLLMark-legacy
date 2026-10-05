def stop_cooking_timer(self, username):
        if username in self.timers:
            self.timers[username].stop_timer()
        else:
            print(f"No timer found for {username}.")