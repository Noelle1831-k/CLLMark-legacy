def check_milestones(self, goal_name):
        '''
        Checks if any milestones for a goal have been reached.
        '''
        goal = self.goal_manager.get_goal(goal_name)
        if goal:
            for milestone in goal['milestones']:
                if goal['current'] >= milestone:
                    print(f"Milestone '{milestone}' reached for goal '{goal_name}'.")
        else:
            print(f"Goal '{goal_name}' not found.")