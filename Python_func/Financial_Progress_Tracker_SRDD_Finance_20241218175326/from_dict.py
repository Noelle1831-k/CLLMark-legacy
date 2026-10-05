def from_dict(cls, data):
        goal = cls(data['name'], data['target_amount'])
        goal.current_amount = data['current_amount']
        goal.milestones = [Milestone.from_dict(m) for m in data['milestones']]
        return goal