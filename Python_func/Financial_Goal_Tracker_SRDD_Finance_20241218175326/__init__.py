def __init__(self, name, target_amount):
        '''
        Initializes a financial goal with a name and a target amount.
        '''
        self.name = name
        self.target_amount = target_amount
        self.current_amount = 0
        self.milestones = []
        self.progress = 0
        self.creation_date = datetime.now()  # Adding creation date for better tracking