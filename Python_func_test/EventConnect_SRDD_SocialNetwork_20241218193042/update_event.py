def update_event(self, name=None, date=None, location=None, type=None):
        if name:
            self.name = name
        if date:
            self.date = date
        if location:
            self.location = location
        if type:
            self.type = type
        print(f"Event updated: {self.name}")