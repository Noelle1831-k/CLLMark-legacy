def calculate_affinity(self, user_preferences):
        affinity = 0
        for activity in self.activities:
            if activity in user_preferences.preferred_activities:
                affinity += 1
        if user_preferences.accommodation_type in self.accommodation_options:
            affinity += 1
        if user_preferences.transportation_mode in self.transportation_options:
            affinity += 1
        return affinity