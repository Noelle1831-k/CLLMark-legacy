def add_activity(self, activity):
        if activity not in self.preferred_activities:
            self.preferred_activities.append(activity)