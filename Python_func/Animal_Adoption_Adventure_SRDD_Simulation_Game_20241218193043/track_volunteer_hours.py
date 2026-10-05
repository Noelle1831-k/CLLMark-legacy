def track_volunteer_hours(self, name, hours):
        if name in self.volunteers:
            self.volunteers[name] += hours
            print(f"Tracked {hours} hours for volunteer {name}. Total hours: {self.volunteers[name]}")