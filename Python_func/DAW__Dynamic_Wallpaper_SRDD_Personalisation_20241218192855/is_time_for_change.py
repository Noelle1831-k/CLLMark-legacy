def is_time_for_change(self):
        # Determine if it's time to change the wallpaper
        current_time = self.get_current_time()
        # Example logic: change every 6 hours
        return current_time.hour % 6 == 0