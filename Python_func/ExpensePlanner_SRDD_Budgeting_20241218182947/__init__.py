def __init__(self, name, email):
        self.name = name
        self.email = email
        self.expenses = []
        self.budget = budget.Budget()
        self.notifications = []