def __init__(self, description, target_amount, goal_id=None):
        '''
        Initialize a budgeting goal with a description and target amount.
        '''
        self.id = goal_id
        self.description = description
        self.target_amount = target_amount