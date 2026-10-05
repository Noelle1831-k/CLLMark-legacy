def sell_tickets(self, ticket_price, capacity, lineup, artists):
        '''
        Simulates ticket sales based on capacity, ticket price, and lineup popularity.
        '''
        # Simulate ticket sales based on lineup popularity and venue capacity
        demand_factor = len(lineup) / len(artists)  # Example factor based on lineup
        tickets_sold = min(int(capacity * demand_factor), capacity)
        self.total_sold += tickets_sold
        print(f"Sold {tickets_sold} tickets at ${ticket_price} each.")
        return tickets_sold