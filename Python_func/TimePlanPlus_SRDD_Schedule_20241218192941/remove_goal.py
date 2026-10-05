def remove_goal(self, name):
        if name in self.goals:
            del self.goals[name]
            print(f"Goal '{name}' removed.")
        else:
            print(f"Goal '{name}' not found.")