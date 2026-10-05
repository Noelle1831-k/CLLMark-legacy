def input_event_details(self):
        self.event_details["date"] = input("Enter event date (YYYY-MM-DD): ")
        self.event_details["time"] = input("Enter event time (HH:MM): ")
        self.event_details["location"] = input("Enter event location: ")
        self.event_details["sport"] = input("Enter type of sport: ")