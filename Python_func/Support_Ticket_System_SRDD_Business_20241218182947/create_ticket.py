def create_ticket(self, description, priority):
        ticket_id = generate_ticket_id()
        ticket = Ticket(ticket_id, description, priority)
        self.tickets.append(ticket)
        print(f"Ticket created: {ticket}")