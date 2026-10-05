def remove_event_ui(self):
        title = input("Enter the title of the event to remove: ")
        matching_events = [event for event in self.schedule.events if event.title == title]
        if not matching_events:
            print("No events found with that title.")
            return
        print("Matching events:")
        for i, event in enumerate(matching_events):
            print(f"{i + 1}.")
            event.display_event()
        choice = int(input("Enter the number of the event to remove: ")) - 1
        if 0 <= choice < len(matching_events):
            self.schedule.remove_event(matching_events[choice].event_id)
            print("Event removed successfully.")
        else:
            print("Invalid selection.")