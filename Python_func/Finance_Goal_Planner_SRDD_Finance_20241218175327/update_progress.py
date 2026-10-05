def update_progress(self, goal_name, amount):
        '''
        Updates the progress for a given goal by a specified amount.
        '''
        goal = self.goal_manager.get_goal(goal_name)
        if goal:
            goal['current'] += amount
            print(f"Progress updated for '{goal_name}'. Current amount: {goal['current']}.")
        else:
            print(f"Goal '{goal_name}' not found.")