def create_study_plan(self):
        preferences = self.user.get_preferences()
        daily_time = preferences.get("daily_study_time", 30)
        days = preferences.get("preferred_study_days", ["Monday", "Wednesday", "Friday"])
        for day in days:
            self.study_plan.append((day, daily_time))