def create_event(self, name, date, time, location, interests):
        event = {"name": name, "date": date, "time": time, "location": location, "interests": interests}
        self.events.append(event)
        print(f"Event {name} created successfully.")