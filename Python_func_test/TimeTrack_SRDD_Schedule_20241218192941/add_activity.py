def add_activity(self, activity):
        if activity not in self.activities:
            self.activities.append(activity)
            print(f"Activity '{activity}' added.")
        else:
            print(f"Activity '{activity}' already exists.")