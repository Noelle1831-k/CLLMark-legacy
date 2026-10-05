def add_milestone(self, goal_name, milestone):
        '''
        Adds a milestone to a given goal.
        '''
        goal = self.goal_manager.get_goal(goal_name)
        if goal:
            goal['milestones'].append(milestone)
            print(f"Milestone '{milestone}' added to goal '{goal_name}'.")
        else:
            print(f"Goal '{goal_name}' not found.")