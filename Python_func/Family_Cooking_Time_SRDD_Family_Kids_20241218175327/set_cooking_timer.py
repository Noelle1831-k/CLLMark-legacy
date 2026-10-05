def set_cooking_timer(self, username, duration):
        if username in self.timers:
            print(f"Timer already set for {username}.")
        else:
            timer = CookingTimer()
            timer.set_timer(duration)
            self.timers[username] = timer
            print(f"Timer set for {username} for {duration} seconds.")