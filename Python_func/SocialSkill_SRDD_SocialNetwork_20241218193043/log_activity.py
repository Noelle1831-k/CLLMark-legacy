def log_activity(self, user, exercise_name, result):
        if user.username not in self.logs:
            self.logs[user.username] = []
        self.logs[user.username].append((exercise_name, result))
        print(f"Logged {exercise_name} result for {user.username}: {result}")