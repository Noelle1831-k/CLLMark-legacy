def delete_event(self, name):
        for event in self.events:
            if event['name'] == name:
                self.events.remove(event)
                print(f"Event {name} deleted successfully.")
                return
        print("Event not found.")