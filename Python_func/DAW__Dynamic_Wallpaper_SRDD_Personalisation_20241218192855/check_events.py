def check_events(self):
        # Check and trigger events
        for event, wallpaper in self.events.items():
            print(f"Event {event} triggered for {wallpaper.filename}")