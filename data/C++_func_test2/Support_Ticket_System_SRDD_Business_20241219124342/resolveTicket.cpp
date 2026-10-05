void Agent::resolveTicket(Ticket& ticket) {
    for (int i = 0; i < assignedTickets.size(); i++) {
        if (assignedTickets[i].getID() == ticket.getID()) {
            assignedTickets[i].updateStatus("Resolved");
        }
    }
}