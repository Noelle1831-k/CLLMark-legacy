void TicketSystem::generateReport() const {
    cout << "Ticket System Report:" << endl;
    for (int i = 0; i < tickets.size(); i++) {
        cout << "Ticket ID: " << tickets[i].getID()
             << ", Priority: " << tickets[i].getPriority()
             << ", Status: " << tickets[i].getStatus() << endl;
    }
}