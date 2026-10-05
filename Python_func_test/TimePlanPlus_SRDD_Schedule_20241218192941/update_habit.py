def update_habit(self, name, progress=None):
        if name in self.habits:
            if progress is not None:
                self.habits[name]['progress'] = progress
            print(f"Habit '{name}' updated.")
        else:
            print(f"Habit '{name}' not found.")