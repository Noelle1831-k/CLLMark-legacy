def set_wallpaper(self):
        # Set wallpaper based on time or event
        current_time = self.time_manager.get_current_time()
        selected_wallpaper = self.select_wallpaper_based_on_time(current_time)
        if selected_wallpaper:
            selected_wallpaper.display()