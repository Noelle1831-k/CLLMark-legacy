def __init__(self, ticket_id, description, priority):
        self.ticket_id = ticket_id
        self.description = description
        self.priority = priority
        self.status = "Open"
        self.assigned_agent = None