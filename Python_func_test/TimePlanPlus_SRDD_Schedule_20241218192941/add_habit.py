def add_habit(self, name):
        self.habits[name] = {'progress': 0}
        print(f"Habit '{name}' added.")