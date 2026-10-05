def to_dict(self):
        return {
            'name': self.name,
            'target_amount': self.target_amount,
            'current_amount': self.current_amount,
            'milestones': [milestone.to_dict() for milestone in self.milestones]
        }