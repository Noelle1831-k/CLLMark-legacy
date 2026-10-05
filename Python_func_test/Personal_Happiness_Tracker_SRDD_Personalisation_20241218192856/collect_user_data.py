def collect_user_data(self):
        mood = self.user.input_mood()
        activities = self.user.input_activities()
        events = self.user.input_events()
        return {'mood': mood, 'activities': activities, 'events': events}