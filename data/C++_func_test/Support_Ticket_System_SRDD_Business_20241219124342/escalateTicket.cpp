void Ticket::escalateTicket() {
    if (priority == "Low") {
        priority = "Medium";
    } else if (priority == "Medium") {
        priority = "High";
    } else if (priority == "High") {
        cout << "Ticket " << id << " is already at the highest priority." << endl;
    }
}