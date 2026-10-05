def remove_activity(self, activity):
        if activity in self.activities:
            self.activities.remove(activity)
            print(f"Activity '{activity}' removed.")
        else:
            print(f"Activity '{activity}' not found.")