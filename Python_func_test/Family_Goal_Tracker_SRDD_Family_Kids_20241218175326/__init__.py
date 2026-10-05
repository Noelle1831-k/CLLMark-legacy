def __init__(self, title, description):
        self.title = title
        self.description = description
        self.assigned_member = None
        self.deadline = None
        self.status = "Not Started"
        self.progress = 0  # Added attribute to track progress