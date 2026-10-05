def create_event(self):
        self.db.add_event(self)
        print(f"Event created: {self.name}")