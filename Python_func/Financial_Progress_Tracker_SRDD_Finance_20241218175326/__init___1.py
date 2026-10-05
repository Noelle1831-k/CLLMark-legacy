def __init__(self, name, target_amount):
        self.name = name
        self.target_amount = target_amount
        self.reached = False
        self.notified = False