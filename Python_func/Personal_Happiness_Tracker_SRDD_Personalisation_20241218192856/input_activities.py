def input_activities(self):
        activities = input("List your activities for today (comma-separated): ")
        self.activities = [activity.strip() for activity in activities.split(',')]
        return self.activities