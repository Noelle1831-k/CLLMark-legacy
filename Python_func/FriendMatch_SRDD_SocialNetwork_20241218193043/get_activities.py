def get_activities(self, user):
        return self.activities.get(user, [])