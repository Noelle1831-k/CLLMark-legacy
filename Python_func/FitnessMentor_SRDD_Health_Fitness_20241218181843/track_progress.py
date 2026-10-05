def track_progress(self, username, workout_data):
        user = self.login_user(username)
        tracker = Tracker(user)
        tracker.log_workout(workout_data)
        return tracker.analyze_progress()