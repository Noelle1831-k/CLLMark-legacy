def from_dict(cls, data):
        milestone = cls(data['name'], data['target_amount'])
        milestone.reached = data['reached']
        milestone.notified = data['notified']
        return milestone