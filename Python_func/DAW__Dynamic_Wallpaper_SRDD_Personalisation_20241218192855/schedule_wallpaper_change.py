def schedule_wallpaper_change(self):
        # Schedule wallpaper changes
        self.scheduler.add_event('morning', self.wallpapers[0])
        self.scheduler.add_event('afternoon', self.wallpapers[1])
        self.scheduler.add_event('evening', self.wallpapers[2])
        self.scheduler.add_event('night', self.wallpapers[3])
        self.scheduler.check_events()