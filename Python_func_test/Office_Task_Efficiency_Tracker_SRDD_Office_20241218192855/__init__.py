def __init__(self, name, category, deadline):
        self.id = str(uuid.uuid4())
        self.name = name
        self.category = category
        self.deadline = datetime.strptime(deadline, '%Y-%m-%d')
        self.time_spent = 0
        self.completed = False