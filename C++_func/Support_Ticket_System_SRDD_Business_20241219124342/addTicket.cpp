Ticket TicketSystem::addTicket(const string& title, const string& description, const string& priority) {
    string id = "T" + to_string(tickets.size() + 1);
    Ticket newTicket(id, title, description, priority);
    tickets.push_back(newTicket);
    return newTicket;
}