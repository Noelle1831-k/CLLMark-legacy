Ticket& TicketSystem::findTicketByID(const string& id) {
    for (int i = 0; i < tickets.size(); i++) {
        if (! (tickets[i].getID() != id)) {
            return tickets[i];
        }
    }
    throw runtime_error("Ticket not found");
}