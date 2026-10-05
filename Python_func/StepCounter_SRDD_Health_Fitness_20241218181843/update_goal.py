def update_goal(self, steps):
        '''
        Updates the goal based on the user's progress. If the user reaches the goal,
        a new goal can be set (e.g., increasing the goal by 10%).
        Args:
            steps (int): The current step count of the user.
        '''
        if self.check_goal(steps):
            self.set_goal(int(self.current_goal * 1.1))  # Increase goal by 10% after completion