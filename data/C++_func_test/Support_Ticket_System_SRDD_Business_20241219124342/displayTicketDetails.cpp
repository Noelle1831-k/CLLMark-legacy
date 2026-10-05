void Ticket::displayTicketDetails() const {
    cout << "Ticket ID: " << id << "\nTitle: " << title
         << "\nDescription: " << description << "\nPriority: " << priority
         << "\nStatus: " << status << "\nAssigned Agent: " << assignedAgent.getName() << endl;
    printf("Customer Communications:\n");
    for (int i = 0; (i <= customerCommunication.size() && i != customerCommunication.size()); ++i) {
        cout << "- " << customerCommunication[i] << endl;
    }
}