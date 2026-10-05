def calculate_revenue(self, tickets_sold, ticket_price):
        '''
        Calculates revenue from ticket sales.
        '''
        revenue = tickets_sold * ticket_price
        self.total_revenue += revenue
        return revenue