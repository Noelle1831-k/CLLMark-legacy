def assign_ticket_to_agent(self, ticket_id, agent_id):
        ticket = next((t for t in self.tickets if t.ticket_id == ticket_id), None)
        agent = next((a for a in self.agents if a.agent_id == agent_id), None)
        if ticket and agent:
            agent.assign_ticket(ticket)
            print(f"Ticket {ticket_id} assigned to agent {agent_id}.")
        else:
            print("Ticket or agent not found.")