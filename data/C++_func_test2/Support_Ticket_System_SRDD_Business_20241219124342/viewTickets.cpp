void Agent::viewTickets() const {
    cout << "Agent " << name << " Tickets:" << endl;
    for (int i = 0; i < assignedTickets.size(); i++) {
        cout << "Ticket ID: " << assignedTickets[i].getID()
             << ", Status: " << assignedTickets[i].getStatus() << endl;
    }
}