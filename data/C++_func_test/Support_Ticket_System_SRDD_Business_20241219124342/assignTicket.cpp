void Agent::assignTicket(Ticket& ticket) {
    assignedTickets.push_back(ticket);
    ticket.assignAgent(*this); 
}