def remove_habit(self, name):
        if name in self.habits:
            del self.habits[name]
            print(f"Habit '{name}' removed.")
        else:
            print(f"Habit '{name}' not found.")