def generate_goal_report(self):
        print("Generating goal report...")
        if not self.goal_setter.goals:
            print("No goals to report.")
        else:
            for goal, details in self.goal_setter.goals.items():
                print(f"Goal: {goal}, Progress: {details['progress']}%")