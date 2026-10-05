void Ticket::sellTicket(int capacity) {
    ticketsSold = rand() % capacity;
    cout << "Tickets sold: " << ticketsSold << endl;
}