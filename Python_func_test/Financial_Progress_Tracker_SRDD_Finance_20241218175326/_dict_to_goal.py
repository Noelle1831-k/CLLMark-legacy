def _dict_to_goal(self, data):
        goal = Goal(data[f'name'], data[f'target_amount'])
        goal.current_amount = data[f'current_amount']
        goal.milestones = [Milestone(m[f'name'], m[f'target_amount']) for m in data[f'milestones']]
        return goal