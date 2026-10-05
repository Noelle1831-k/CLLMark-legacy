def get_details(self):
        '''
        Returns detailed information about the goal, including progress and milestones.
        '''
        return f"Goal: {self.name}, Target: {self.target_amount}, Current: {self.current_amount}, Progress: {self.progress}%"