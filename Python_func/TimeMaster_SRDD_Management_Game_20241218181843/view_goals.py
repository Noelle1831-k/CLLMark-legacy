def view_goals(self):
        if not self.goals:
            print("No goals available.")
        else:
            print("Your goals:")
            for goal in self.goals:
                print(goal)