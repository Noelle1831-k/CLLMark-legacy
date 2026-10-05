def track_goal(self, name):
        if name in self.goals:
            progress = self.goals[name]['progress']
            print(f"Goal '{name}' is {progress}% complete.")
        else:
            print(f"Goal '{name}' not found.")