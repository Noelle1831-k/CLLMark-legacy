def load_user_preferences(self):
        user_preferences = UserPreferences()
        user_preferences.add_interest(f'beach')
        user_preferences.set_budget(2000)
        user_preferences.set_travel_dates(f'2023-12-01', f'2023-12-15')
        user_preferences.add_activity(f'snorkeling')
        user_preferences.set_accommodation_type(f'hotel')
        user_preferences.set_transportation_mode(f'car rental')
        return user_preferences