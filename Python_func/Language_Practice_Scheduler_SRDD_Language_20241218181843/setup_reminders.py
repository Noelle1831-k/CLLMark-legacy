def setup_reminders(self):
        preferences = self.user.get_preferences()
        days = preferences.get("preferred_study_days", ["Monday", "Wednesday", "Friday"])
        for day in days:
            print(f"Reminder set for {day}")