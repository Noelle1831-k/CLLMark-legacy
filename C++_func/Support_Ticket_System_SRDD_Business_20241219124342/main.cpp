int main() {
    TicketSystem system;
    Agent agent1("A001", "John Doe");
    Agent agent2("A002", "Jane Smith");
    system.addAgent(agent1);
    system.addAgent(agent2);
    Ticket ticket1 = system.addTicket("Issue with login", "User cannot login to the system", "High");
    Ticket ticket2 = system.addTicket("Page not loading", "User reports homepage is not loading", "Medium");
    system.findTicketByID(ticket1.getID()).assignAgent(agent1);
    system.findTicketByID(ticket2.getID()).assignAgent(agent2);
    system.findTicketByID(ticket1.getID()).addCommunication("User reported issue resolved after password reset.");
    system.findTicketByID(ticket2.getID()).addCommunication("Investigated issue, seems to be network-related.");
    system.findTicketByID(ticket1.getID()).updateStatus("Resolved");
    system.findTicketByID(ticket2.getID()).escalateTicket();
    system.findTicketByID(ticket2.getID()).updateStatus("In Progress");
    system.generateReport();
    return 0;
}