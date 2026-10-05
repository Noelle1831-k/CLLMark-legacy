def check_goal(self):
        if self.current_amount >= self.goal_amount:
            print(f"Goal '{self.goal_name}' achieved!")
            return True
        else:
            print(f"Goal '{self.goal_name}' not yet achieved. Current progress: {self.current_amount}/{self.goal_amount}")
            return False