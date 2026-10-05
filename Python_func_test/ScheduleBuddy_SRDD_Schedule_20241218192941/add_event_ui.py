def add_event_ui(self):
        title = input("Enter event title: ")
        date = input("Enter event date (YYYY-MM-DD): ")
        while not validate_date(date):
            print("Invalid date format.")
            date = input("Enter event date (YYYY-MM-DD): ")
        time = input("Enter event time (HH:MM): ")
        while not validate_time(time):
            print("Invalid time format.")
            time = input("Enter event time (HH:MM): ")
        location = input("Enter event location: ")
        description = input("Enter event description: ")
        event = Event(title, date, time, location, description)
        self.schedule.add_event(event)
        print("Event added successfully.")