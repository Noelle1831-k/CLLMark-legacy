def manage_bookings(self):
        '''
        Manage bookings for all customers.
        '''
        for customer in self.customers:
            customer.make_booking(self.rooms)
            if customer.booking:
                self.revenue += 100  # Assume each booking generates $100