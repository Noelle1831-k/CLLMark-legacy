def log_event(self, event):
        self.logs.append(event)
        print(f"Event logged: {event}")