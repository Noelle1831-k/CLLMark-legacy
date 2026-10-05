def update_progress(self, performance):
        if performance >= 90:
            self.progress["session"] = "Excellent"
        elif performance >= 75:
            self.progress["session"] = "Good"
        else:
            self.progress["session"] = "Needs Improvement"
        print(f"User progress updated: {self.progress['session']}")