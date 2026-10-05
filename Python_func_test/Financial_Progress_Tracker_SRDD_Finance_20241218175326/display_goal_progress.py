def display_goal_progress(self, goal):
        progress_percentage = (goal.current_amount / goal.target_amount) * 100
        print(f"Goal: {goal.name}")
        print(f"Progress: {goal.current_amount}/{goal.target_amount} ({progress_percentage:.2f}%)")
        self.display_progress_bar(progress_percentage)
        self.display_estimated_completion(goal)