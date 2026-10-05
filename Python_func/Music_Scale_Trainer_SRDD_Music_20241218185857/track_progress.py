def track_progress(self):
        username = self.profile['username']
        self.progress[username]['completed_exercises'] += 1
        print(f"Progress for {username}: {self.progress[username]['completed_exercises']} exercises completed.")