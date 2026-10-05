def resolve_ticket(self, ticket):
        if ticket in self.assigned_tickets:
            ticket.update_status("Resolved")
            self.assigned_tickets.remove(ticket)