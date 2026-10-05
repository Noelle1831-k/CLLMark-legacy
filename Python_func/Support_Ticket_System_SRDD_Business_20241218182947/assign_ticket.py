def assign_ticket(self, ticket):
        self.assigned_tickets.append(ticket)
        ticket.assign_agent(self)