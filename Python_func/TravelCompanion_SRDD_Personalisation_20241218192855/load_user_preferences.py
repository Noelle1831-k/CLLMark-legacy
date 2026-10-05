def load_user_preferences(self):
        user_preferences = UserPreferences()
        user_preferences.add_interest("beach")
        user_preferences.set_budget(2000)
        user_preferences.set_travel_dates("2023-12-01", "2023-12-15")
        user_preferences.add_activity("snorkeling")
        user_preferences.set_accommodation_type("hotel")
        user_preferences.set_transportation_mode("car rental")
        return user_preferences