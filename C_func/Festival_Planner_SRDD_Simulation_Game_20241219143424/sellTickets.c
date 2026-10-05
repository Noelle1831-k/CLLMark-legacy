void sellTickets(TicketSales *sales) {
    sales->ticketsSold += 100; 
    sales->revenue += 1000.0; 
    printf("Tickets sold: %d, Revenue: %.2f\n", sales->ticketsSold, sales->revenue);
}