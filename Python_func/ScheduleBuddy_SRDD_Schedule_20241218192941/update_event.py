def update_event(self, title=None, date=None, time=None, location=None, description=None):
        if title:
            self.title = title
        if date:
            self.date = date
        if time:
            self.time = time
        if location:
            self.location = location
        if description:
            self.description = description