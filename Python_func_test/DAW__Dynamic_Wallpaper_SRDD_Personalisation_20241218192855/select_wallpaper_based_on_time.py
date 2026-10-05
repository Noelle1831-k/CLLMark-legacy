def select_wallpaper_based_on_time(self, current_time):
        # Select wallpaper dynamically based on time
        if 6 <= current_time.hour < 12:
            return self.wallpapers[0]  # Morning wallpaper
        elif 12 <= current_time.hour < 18:
            return self.wallpapers[1]  # Afternoon wallpaper
        elif 18 <= current_time.hour < 24:
            return self.wallpapers[2]  # Evening wallpaper
        else:
            return self.wallpapers[3]  # Night wallpaper