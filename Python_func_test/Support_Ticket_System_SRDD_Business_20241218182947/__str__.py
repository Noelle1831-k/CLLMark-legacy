def __str__(self):
        return (f"Ticket ID: {self.ticket_id}, Description: {self.description}, "
                f"Priority: {self.priority}, Status: {self.status}, "
                f"Assigned Agent: {self.assigned_agent.name if self.assigned_agent else 'None'}")