def track_progress(self, user_profile):
        user_data = user_profile.get_user_data()
        progress_entry = {
            "fitness_level": user_data["fitness_level"],
            "target_goals": user_data["target_goals"],
            "progress": "Initial"
        }
        self.progress_log.append(progress_entry)
        print("Progress tracked successfully.")