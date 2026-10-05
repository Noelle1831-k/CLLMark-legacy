def run_festival_cycle(self):
        '''
        Simulates one cycle of the festival, including ticket sales, logistics, and revenue.
        '''
        print("\nFestival Cycle: Preparing...")
        venue = choice(self.venues)
        print(f"Selected Venue: {venue.name} - Capacity: {venue.capacity}")
        venue.simulate_weather()
        self.generate_lineup()
        ticket_price = len(self.lineup) * 10  # Dynamic pricing based on lineup
        tickets_sold = self.tickets.sell_tickets(ticket_price, venue.capacity, self.lineup, self.artists)
        print(f"Tickets Sold: {tickets_sold}")
        revenue = self.finance.calculate_revenue(tickets_sold, ticket_price)
        print(f"Cycle Revenue: ${revenue}")