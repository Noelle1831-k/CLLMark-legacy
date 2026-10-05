def set_goal(self, name):
        self.goals[name] = {'progress': 0}
        print(f"Goal '{name}' set.")