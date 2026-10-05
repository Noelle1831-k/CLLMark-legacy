def update_goal(self, name, progress=None):
        if name in self.goals:
            if progress is not None:
                self.goals[name]['progress'] = progress
            print(f"Goal '{name}' updated.")
        else:
            print(f"Goal '{name}' not found.")