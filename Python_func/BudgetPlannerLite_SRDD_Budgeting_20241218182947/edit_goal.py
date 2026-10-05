def edit_goal(self, goal_id, new_description, new_target_amount):
        '''
        Edit an existing goal entry.
        '''
        for goal in self.goals:
            if goal.id == goal_id:
                goal.description = new_description
                goal.target_amount = new_target_amount
                self.db.update_goal(goal)
                break