TicketSales* createTicketSales() {
    TicketSales *sales = (TicketSales*)malloc(sizeof(TicketSales));
    sales->ticketsSold = 0;
    sales->revenue = 0.0;
    return sales;
}