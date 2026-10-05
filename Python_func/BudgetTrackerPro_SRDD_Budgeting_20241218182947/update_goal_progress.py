def update_goal_progress(self, amount):
        self.current_amount += amount
        self.goal_progress.append(amount)
        print(f"Updated progress for goal '{self.goal_name}': {self.current_amount}/{self.goal_amount}")