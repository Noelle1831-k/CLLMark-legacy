def start_cooking_timer(self, username):
        if username in self.timers:
            self.timers[username].start_timer()
        else:
            print(f"No timer found for {username}.")