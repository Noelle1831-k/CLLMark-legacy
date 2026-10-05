def make_booking(self, rooms):
        '''
        Make a booking for the customer.
        '''
        for room in rooms:
            if room.check_availability():
                room.book_room()
                self.booking = room.room_number
                print(f"{self.name} booked Room {self.booking}")
                break
        if not self.booking:
            print(f"No available rooms for {self.name}")