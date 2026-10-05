def track_goal(self):
        if not self.goals:
            print("No goals to track.")
        else:
            print("Tracking goals...")
            for goal in self.goals:
                print(f"Goal: {goal}")