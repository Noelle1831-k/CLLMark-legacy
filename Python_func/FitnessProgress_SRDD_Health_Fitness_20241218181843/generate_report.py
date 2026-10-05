def generate_report(self, username):
        # Generate a progress report
        progress = self.calculate_progress(username)
        report = f"User {username} has covered a total distance of {progress} km."
        return report