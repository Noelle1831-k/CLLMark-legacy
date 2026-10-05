def modify_event(self, name, new_date=None, new_time=None, new_location=None, new_interests=None):
        for event in self.events:
            if event['name'] == name:
                if new_date:
                    event['date'] = new_date
                if new_time:
                    event['time'] = new_time
                if new_location:
                    event['location'] = new_location
                if new_interests:
                    event['interests'] = new_interests
                print(f"Event {name} modified successfully.")
                return
        print("Event not found.")