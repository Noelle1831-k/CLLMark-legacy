def update_goal(self, goal_description=None, start_date=None, end_date=None):
        if goal_description:
            self.goal_description = goal_description
        if start_date:
            self.start_date = start_date
        if end_date:
            self.end_date = end_date