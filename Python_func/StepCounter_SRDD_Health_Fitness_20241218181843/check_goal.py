def check_goal(self, steps):
        '''
        Checks if the user has achieved their daily goal.
        Args:
            steps (int): The number of steps taken so far.
        Returns:
            bool: True if the goal is achieved, False otherwise.
        '''
        return steps >= self.current_goal