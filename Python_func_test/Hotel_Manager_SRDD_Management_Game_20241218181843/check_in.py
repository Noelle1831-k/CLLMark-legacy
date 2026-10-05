def check_in(self):
        '''
        Check-in the customer.
        '''
        if self.booking:
            print(f"{self.name} checked into Room {self.booking}")
        else:
            print(f"{self.name} has no booking to check-in")