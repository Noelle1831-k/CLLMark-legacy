def _dict_to_goal(self, data):
        goal = Goal(data['name'], data['target_amount'])
        goal.current_amount = data['current_amount']
        goal.milestones = [Milestone(m['name'], m['target_amount']) for m in data['milestones']]
        return goal