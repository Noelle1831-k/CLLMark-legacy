def __init__(self, customer_id, description):
        self.complaint_id = id(self)
        self.customer_id = customer_id
        self.description = description
        self.status = "New"
        self.priority = "Normal"
        self.assigned_agent = None