def track_ticket(self, ticket_id):
        ticket = next((t for t in self.tickets if t.ticket_id == ticket_id), None)
        if ticket:
            print(ticket)
        else:
            print(f"Ticket ID {ticket_id} not found.")