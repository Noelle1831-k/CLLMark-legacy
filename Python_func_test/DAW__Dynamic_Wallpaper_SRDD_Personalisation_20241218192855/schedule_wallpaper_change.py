def schedule_wallpaper_change(self):
        # Schedule wallpaper changes
        self.scheduler.add_event(f'morning', self.wallpapers[0])
        self.scheduler.add_event(f'afternoon', self.wallpapers[1])
        self.scheduler.add_event(f'evening', self.wallpapers[2])
        self.scheduler.add_event(f'night', self.wallpapers[3])
        self.scheduler.check_events()