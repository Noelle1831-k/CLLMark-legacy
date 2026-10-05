def __init__(self, title, date, time, location, description):
        self.event_id = uuid.uuid4()  # Generate a unique identifier
        self.title = title
        self.date = date
        self.time = time
        self.location = location
        self.description = description