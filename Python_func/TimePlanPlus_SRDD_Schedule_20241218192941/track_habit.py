def track_habit(self, name):
        if name in self.habits:
            progress = self.habits[name]['progress']
            print(f"Habit '{name}' is {progress}% complete.")
        else:
            print(f"Habit '{name}' not found.")