def track_progress(self, username):
        if username in self.users:
            progress = self.users[username]['progress']
            print(f"{username}'s progress: {progress}%")
        else:
            print("User not found.")