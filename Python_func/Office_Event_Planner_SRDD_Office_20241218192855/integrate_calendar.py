def integrate_calendar(self):
        if self.events:
            event_date = datetime.strptime(self.events[-1].date, "%Y-%m-%d")
            calendar_entry = f"Event: {self.events[-1].name} on {event_date.strftime('%A, %d %B %Y')}"
            self.events[-1].calendar_entry = calendar_entry